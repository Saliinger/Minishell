/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m0rgenstern <m0rgenstern@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:43:42 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/07/27 00:43:21 by m0rgenstern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_command(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	if (paths == NULL)
		return (NULL);
	i = 0;
	if (!cmd)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

int	ft_exec_command(t_pipex *p, char *argv[], int index)
{
	int		err;
	char	*msg;

	p->args = ft_custom_split(argv[index], ' ');
	p->cmd = get_command(p->paths, p->args[0]);
	if (p->cmd == NULL)
	{
		msg = ft_strjoin(p->args[0], ": command not found\n");
		ft_putstr_fd(msg, STDERR_FILENO);
		return (free(msg), ft_free_args(p), ft_error("error cmd\n", ERR_CMD));
	}
	else
	{
		err = execve(p->cmd, p->args, p->env);
		if (err == -1)
		{
			ft_free_args(p);
			ft_free_paths(p);
			exit(ft_error("error execve\n", -1));
		}
	}
	return (0);
}
