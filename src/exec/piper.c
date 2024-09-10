/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:30 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/10 01:16:14 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : adds the new child to known pids
 * 
 */
static int	parent(t_command *c, t_pids *pids, pid_t child_pid)
{
	int	err;

	err = 0;
	if (dup2(c->pipe_fds[IN], STDIN_FILENO) == -1)
		err += -1;
	pids = pids_addfront(pids, child_pid);
	if (!pids)
		err += ERR_MALLOC;
	// if signal recieved, send it to known children here ?
	err += ft_close_fd(&c->pipe_fds[IN]);
	err += ft_close_fd(&c->pipe_fds[OUT]);
	if (err)
		return (ERR_PARENT);
	return (0);
}

/**
 * brief : exeve the command in c, with the env in m
 * 
 */
static int	child(t_command *c, t_minishell *m)
{
	int	err;

	err = 0;
	if (c->infile_fd != -1)
	{
		if (dup2(c->infile_fd, STDIN_FILENO) == -1)
			err += -1;
	}
	if (c->outfile_fd != -1)
	{
		if (dup2(c->outfile_fd, STDOUT_FILENO) == -1)
			err += -1;
	}
	else if (c->pipe_command != NULL)
		if (dup2(c->pipe_fds[OUT], STDOUT_FILENO) == -1) //maybe I should know if I'm last, not to do that
			err += -1;
	err += ft_close_fd(&c->infile_fd);
	err += ft_close_fd(&c->outfile_fd);
	err += ft_close_fd(&c->pipe_fds[IN]);
	err += ft_close_fd(&c->pipe_fds[OUT]);
	if (err)
		return (ERR_CLOSE);
	execve_command(c, m);
	return (ERR_CHILD);
}

/**
 * brief : for each cmd in cmds, creates a child, notes its pid, and execve the cmd in the child
 * then waits for all the noted pids to be done and returns exit status of the last created child
 * 
 * allocates & frees t_pids 
 */
int	piper(t_command *cmds, t_minishell *m)
{
	pid_t	pid;
	t_pids	*pids; //track me to check if I'm implemented good

	pids = NULL;
	while (cmds)
	{
		if (pipe(cmds->pipe_fds) == -1)
			return (ft_error("pipe error\n", ERR_OUT));
		// if signal recieved, send it to known children here ?
		pid = fork();
		if (pid == -1)
			return (free_pids(pids), ft_error("fork error\n", ERR_FORK));
		if (pid == 0)
		{
			if (child(cmds, m) == ERR_CHILD)
				return (free_pids(pids), ft_error("child err\n", ERR_CHILD));
		}
		else
			if (parent(cmds, pids, pid) == ERR_PARENT) //pids is not yet a linked list
				return (free_pids(pids), ft_error("parent error\n", ERR_PARENT));
		cmds = cmds->pipe_command;
	}
	return (parent_waits(cmds, pids, pid));
}
