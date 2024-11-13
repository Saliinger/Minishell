/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:03 by ekrebs            #+#    #+#             */
/*   Updated: 2024/10/23 18:36:23 by ekrebs           ###   ########.fr       */
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
 * brief : will exec the command (cmd located in c->cmd_args[0], args c->cmd_args, paths located in m->paths) 
 * 
 */
static int	execve_cmdpath(t_command_exec *c, t_minishell *m)
{
	int		err;
	char	*msg;
	char	*cmd_path;

	err = 0;
	cmd_path = get_command(m->paths, c->cmd_args[0]);
	if (cmd_path == NULL)
	{
		msg = ft_strjoin(c->cmd_args[0], ": command not found\n");
		ft_putstr_fd(msg, STDERR_FILENO);
		return (free(msg), ft_error("error cmd\n", ERR_CMD));
	}
	err = execve(cmd_path, c->cmd_args, m->env);
	perror("minishell");																														
	return (err);
}

/**
 * brief : will exec the command
 * note : children either get execve'd here or get exit(-1) for failure to execve
 * if execve fails, frees everything and EXITS
 */
void	execve_command(t_command_exec *c, t_minishell *m, t_pids *pids)
{
	int		err;

	err = execve_cmdpath(c, m);
	free_t_command_exec(&c);
	free_t_minishell(&m);
	free_pids(pids);
	if (err)
		exit(err);
	exit(EXIT_SUCCESS);
}
