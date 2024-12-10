/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:38:41 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/30 03:36:34 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
/**
 * brief : this version waits for any child to die, if the last child died, returns by pointer it's exit status
 * 
 */
static int	wait_get_child_err(pid_t last_child_pid, int *last_child_exit_status, bool *jump_sigint)
{
	pid_t	got_pid;
	int		status;

	status = 0;
	got_pid = wait(&status);
	if (got_pid == -1)
			return (perror("wait"), ERR_PRIM);
	if (got_pid == last_child_pid && WIFEXITED(status))
		*last_child_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (got_pid == last_child_pid)
		{
			*last_child_exit_status = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGQUIT)
				write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
		}
		if (WTERMSIG(status) == SIGINT && *jump_sigint)
		{
			write(STDOUT_FILENO, "\n", 1);
			*jump_sigint = false;
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * brief : waits for all children to die, returns the exit status of the last child
 * returns 128 + SIG num if child killed by signal.
 * 
 */
static int	wait_children (t_pids *pids, pid_t last_child_pid)
{
	int		err;
	int		err_last_child;
	int		nb_children;
	bool	jump_sigint;

	err = 0;
	err_last_child = 0;
	jump_sigint = true;
	nb_children = pids_size(pids);
	while (nb_children > 0)
	{
		err = wait_get_child_err(last_child_pid, &err_last_child, &jump_sigint);
		nb_children--;
		if (err)
			return (printerr("%s: %d: err", __FILE__, __LINE__), err);
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
static int	parent_waits(t_pids **pids_list, pid_t last_pid, int last_cmd_type)
{
	int		exit_status;

	exit_status = 0;
	if (last_pid > 0)
	{
		exit_status = wait_children(pids_list[0], last_pid);
		if (exit_status == -1)
			return (free_pids(pids_list), printerr("%s: %d: err: exit_status =  %d", __FILE__, __LINE__, exit_status), ERR_PRIM);
		if (exit_status >= 0)
			return (free_pids(pids_list), exit_status);
	}
	else if (last_cmd_type != CMD_BUILTIN)
		return (free_pids(pids_list), printerr("%s: %d: err: last_pid = %d", __FILE__, __LINE__, last_pid), ERR);
	return (free_pids(pids_list), EXIT_SUCCESS);
}

/**
 * brief : gets the exit status from the cmd, 
 * 
 * 'last_cmd_type' is discriminator betwwen behaviours : 
 * (CMD_BUILTIN) will check if should wait for potential children (p.pids_list), then return the builtin_exit_status 
 * (CMD_EXTREN) should wait for children (p.pids_list), extracting ir from last child created (p.pid_last)
 */
int	get_exit_status(t_minishell *m, t_infos *inf)
{
	int	exit_status;

	exit_status = 0;
	if (set_signals_to_ignore() == -1)
	 	return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	ft_close_pipes(inf->cmd_count - 1, &inf->pipes);
	if (inf->last_cmd_type == CMD_BUILTIN)
		parent_waits(&inf->pids_llist, inf->last_pid, inf->last_cmd_type);
	else if (inf->last_cmd_type == CMD_EXTERN)
		m->exit_status[0] = parent_waits(&inf->pids_llist, inf->last_pid, inf->last_cmd_type);
	else
		return(free_t_infos(inf), printerr("minishell: %s: %s: exec failure", __FILE__, __FUNCTION__), ERR);
	return (free_t_infos(inf), exit_status);
}

