/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:03 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/23 03:24:35 by ekrebs           ###   ########.fr       */
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

int	exec_builtin(t_command *c, t_minishell *m)
{
	int	exit_status;

	exit_status = 0;
	if (c->id == ECHO_ID)
		ft_echo(m, c);
	else if (c->id == CD_ID)
		ft_cd(c, m);
	else if (c->id == PWD_ID)
		ft_pwd(m);
	else if (c->id == EXPORT_ID)
		ft_export(c, m);
	else if (c->id == UNSET_ID)
		ft_unset(c, m);
	else if (c->id == ENV_ID)
		ft_env(m);
	else if (c->id == EXIT_ID)
		exit_shell(false);
	return (exit_status);
}

/**
 * brief : will exec the command, makes it work wheter the cmd is a builtin (identified with c->id, args c->arg, path located in m->builtins[c->id]),
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
		exec_builtin(c, m);
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
		perror(NULL);																														
	}
	return (err);
}

/**
 * brief : will exec the command
 * note : children either get execve'd here or get exit(-1) for failure to execve
 */
void	execve_command(t_command *c, t_minishell *m, t_pids *pids)
{
	int		err;

	err = execve_builtin_or_cmdpath(c, m);
	
	free_t_command(&c);
	free_t_minishell(&m);
	free_pids(pids);
	if (err)
		exit(err);
	exit(0);
}
