/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_waits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:38:41 by ekrebs            #+#    #+#             */
/*   Updated: 2024/08/03 18:10:03 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wait_get_child_err(pid_t last_child_pid, int *err_child)
{
	pid_t	waited_pid;
	int		status;

	waited_pid = wait(&status);
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

int	ft_parent_waits(t_pipex *p, int nb_children, pid_t pid)
{
	int		err;
	int		err_last_child;
	pid_t	last_child_pid;

	err = 0;
	err_last_child = 0;
	last_child_pid = pid;
	if (pid != 0)
	{
		while (nb_children > 0)
		{
			err += wait_get_child_err(last_child_pid, &err_last_child);
			nb_children--;
		}
		err += ft_close_fd(&p->fds.infile);
		err += ft_close_fd(&p->fds.outfile);
		if (err)
			return (ERR_PARENT);
		if (err_last_child)
			return (err_last_child);
	}
	return (0);
}
