/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:38:41 by ekrebs            #+#    #+#             */
/*   Updated: 2024/10/20 22:16:21 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : this version waits for any child to die, if the last child died, returns it's exit status
 * 
 */
static int	wait_get_child_err(pid_t last_child_pid, int *err_child)
{
	pid_t	waited_pid;
	int		status;

	waited_pid = wait(&status);
	if (waited_pid == -1)
		return (perror("minishell"), ERR_PRIM);
	if (waited_pid == last_child_pid && WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == ERR_CHILD)
			*err_child = ERR_LAST_CHILD;
	}
	else if (waited_pid == last_child_pid && WIFSIGNALED(status))
		*err_child = 127 + WTERMSIG(status);
	return (EXIT_SUCCESS);
}

/**
 * brief : waits for all children to die, returns the exit status of the last child
 * returns 127 + SIG num if child killed by signal
 * 
 */
static int	wait_children (t_pids *pids, pid_t last_child_pid)
{
	int	err;
	int	err_last_child;
	int	nb_children;

	err = 0;
	nb_children = pids_size(pids);
	while (nb_children > 0)
	{
		err = wait_get_child_err(last_child_pid, &err_last_child);
		nb_children--;
	}
	if (err)
		return (err);
	return (err_last_child);
}

/**
 * brief : waits for all children to die, if != 0, returns the exit status of the last child
 * return ERR_PARENT if failed to close file fds
 * 
 * :info: children have already exited sinc execve_command left them no choice 
 * 
 */
static int	parent_waits(t_pids_info p)
{
	int		exit_status;

	exit_status = 0;
	if (p.last_pid != 0)
	{
		exit_status = wait_children(p.pids_list, p.last_pid);
		if (exit_status == -1)
			return (ERR_PRIM);
		if (exit_status)
			return (free_pids(p.pids_list), exit_status);
		/* testme : not sure if needed since I count on dup2 the std_fds anyway
		err += ft_close(&c->infile_fd);	//fixme : If think this should go to wait_children, but idk how to link the pid & the in/out files fd yet => include the pid to each cmd node ?
		err += ft_close(&c->outfile_fd); //fixme
		if (err)
			return (perror(NULL), free_pids(pids), ERR_PARENT); */
	}
	return (free_pids(p.pids_list), EXIT_SUCCESS);
}

/**
 * brief : gets the exit status from the cmd, 
 * 
 * 'last_cmd_type' is discriminator betwwen behaviours : 
 * (CMD_BUILTIN) will check if should wait for potential children (p.pids_list), then return the builtin_exit_status 
 * (CMD_EXTREN) should wait for children (p.pids_list), extracting ir from last child created (p.pid_last)
 */
int	get_exit_status(t_cmd_type last_cmd_type, t_pids_info externs_pids_infos, int builtin_exit_status)
{
	int	exit_status;

	if (last_cmd_type == CMD_BUILTIN)
	{
		parent_waits(externs_pids_infos);
		exit_status = builtin_exit_status;
	}
	else if (last_cmd_type == CMD_EXTERN)
	{
		exit_status = parent_waits(externs_pids_infos);
	}
	else
		return(ft_printf("minishell: %s: %s: exec failure", __FILE__, __FUNCTION__), ERR_ARGS);
	return (exit_status);
}

