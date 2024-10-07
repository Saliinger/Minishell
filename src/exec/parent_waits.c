/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_waits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:38:41 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/10 00:57:52 by ekrebs           ###   ########.fr       */
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

	waited_pid = wait(&status); // I should waitpid them all to avoid wait collisions in case of the death of a child launched by another program that isn't mine
	if (waited_pid == -1)
		return (ERR_PARENT);
	if (waited_pid == last_child_pid && WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == ERR_CHILD)
			*err_child = ERR_LAST_CHILD;
	}
	else if (waited_pid == last_child_pid && WIFSIGNALED(status))
		*err_child = 127 + WTERMSIG(status);
	return (0);
}

/**
 * brief : waits for all children to die, returns the exit status of the last child
 * returns 127 + SIG num if child killed by signal
 * 
 */
static int	wait_children (t_command *c, t_pids *pids, pid_t last_child_pid)
{
	(void)c; //for the warning
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
		return (ft_error( "wait crashed !\n", err), err);
	return (err_last_child);
}

/**
 * brief : waits for all children to die, if != 0, returns the exit status of the last child
 * return ERR_PARENT if failed to close file fds
 * 
 */
int	parent_waits(t_command *c, t_pids *pids, pid_t last_child_pid)
{
	int		err;
	int		err_last_child;

	err = 0;
	err_last_child = 0;
	if (last_child_pid != 0)
	{
		err_last_child = wait_children(c, pids, last_child_pid);
		if (err_last_child)
			return (free_pids(pids), err_last_child);
		err += ft_close_fd(&c->infile_fd);	//fixme : If think this should go to wait_children, but idk how to link the pid & the in/out files fd yet => include the pid to each cmd node ?
		err += ft_close_fd(&c->outfile_fd); //fixme
		if (err)
			return (free_pids(pids), ERR_PARENT);
	}
	return (free_pids(pids), 0);
}
