/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:03 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/09 22:36:07 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : for each path in paths, will try to joind path and cmd, to get the cmdpath,
 * if the cmdpath is executable, returns it, else continues to search 
 * returns NULL if none found;
 */
static char	*get_command(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	if (!paths || !cmd)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/"); //maybe do only if the last char isnt '/' ?
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

/**
 * brief : will exec the command,makes it work wheter the cmd is a builtin (identified with c->id, args c->arg, path located in m->builtins[c->id]),
 * or if it is a cmdpath (cmd located in c->command, arngs c->arg, paths located in m->paths) 
 * 
 */
static int	execve_builtin_or_cmdpath(t_command *c, t_minishell *m)
{
	int		err;
	char	*msg;

	err = 0;
	if (c->id)
	{
		err = execve(m->builtins_paths[c->id], c->arg, m->env);
	}
	else
	{
		c->command = get_command(m->paths, c->command);
		if (c->command == NULL)
		{
			msg = ft_strjoin(c->command, ": command not found\n");
			ft_putstr_fd(msg, STDERR_FILENO);
			return (free(msg), ft_error("error cmd\n", ERR_CMD));
		}
		err = execve(c->command, c->arg, m->env);
	}
	return (err);
}

/**
 * brief : will exec the command
 * 
 */
int	execve_command(t_command *c, t_minishell *m)
{
	int		err;

	err = execve_builtin_or_cmdpath(c, m);
	if (err == -1)
	{
		free_t_command(c); //do I know all c or should I use head + iterator ?  //free m ?
		exit(ft_error("error execve\n", -1)); //check me later to avoid exiting if possible
	}
	return (0);
}
