/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:59:35 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/08/03 15:38:52 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	parent(t_pipex *p)
{
	int	err;

	err = 0;
	if (dup2(p->pipefd[0], STDIN_FILENO) == -1)
		err += -1;
	err += ft_close_fd(&p->pipefd[1]);
	err += ft_close_fd(&p->pipefd[0]);
	if (err)
		return (ERR_PARENT);
	return (0);
}

static int	child(int i, int argc, char *argv[], t_pipex *p)
{
	int	index;
	int	err;

	err = 0;
	index = i + 2;
	if (index == 2)
		if (dup2(p->fds.infile, STDIN_FILENO) == -1)
			err += -1;
	if (index == argc - 2)
	{
		if (dup2(p->fds.outfile, STDOUT_FILENO) == -1)
			err += -1;
	}
	else
		if (dup2(p->pipefd[1], STDOUT_FILENO) == -1)
			err += -1;
	err += ft_close_fd(&p->fds.infile);
	err += ft_close_fd(&p->fds.outfile);
	err += ft_close_fd(&p->pipefd[0]);
	err += ft_close_fd(&p->pipefd[1]);
	if (err)
		return (ERR_CLOSE);
	ft_exec_command(p, argv, index);
	return (ERR_CHILD);
}

int	ft_pipex(t_pipex *p, char *argv[], int argc)
{
	pid_t	pid;
	int		nb_pipes;
	int		i;

	i = 0;
	nb_pipes = argc -4;
	while (i <= nb_pipes)
	{
		if (pipe(p->pipefd) == -1)
			return (ft_error("pipe error\n", ERR_OUT));
		pid = fork();
		if (pid == -1)
			return (ft_error("fork error\n", ERR_FORK));
		if (pid == 0)
		{
			if (child(i, argc, argv, p) == ERR_CHILD)
				return (ft_error("child err\n", ERR_CHILD));
		}
		else
			if (parent(p) == ERR_PARENT)
				return (ft_error("parent error\n", ERR_PARENT));
		i++;
	}
	return (ft_parent_waits(p, i, pid));
}
