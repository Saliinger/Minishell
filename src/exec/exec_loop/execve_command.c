/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:03 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 15:12:02 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"
#include "utils.h"

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
	if (access(cmd, 0) == 0)
		return (cmd);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/"); //maybe do only if the last char isnt '/' ?
		if (!tmp)
			return (NULL);
		command = ft_strjoin(tmp, cmd);
		if (!command)
			return (free(tmp), NULL);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

/**
 * brief : returns tab of paths found in the env, 
 * if fails, returns NULL
 * 
 *  */
static char	**get_env_paths(t_minishell *m)
{
	char	*line_paths;
	char	**result;

	line_paths = ft_getenv(m->env, "PATH");
		result = ft_split(line_paths, ':');
	if (!result)
		return (NULL);
	return (result);
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
	char	**env_paths;

	err = 0;
	if (access(c->cmd_args[0], 0) != 0)
	{
		env_paths = get_env_paths(m);
		cmd_path = get_command(env_paths, c->cmd_args[0]);
	}
	else
		cmd_path = c->cmd_args[0];
	if (cmd_path == NULL)
	{
		msg = ft_strjoin(c->cmd_args[0], ": command not found\n");
		if (!msg)
			return (2);
		ft_putstr_fd(msg, STDERR_FILENO);
		return (free(msg), free_tab(env_paths), ft_error("error cmd\n", 127));
	}
	if (c->cmd_id != MINISHELL_ID)
	{ // CHANGE ME, pour l'instant : pas d'imbrications.
		if (set_signals_to_default() == -1)
			return (printerr("%s: %d: err\n", __FILE__, __LINE__));
		err = execve(cmd_path, c->cmd_args, m->env->my_env);
		perror("execve");
	}
	else
		printerr("mini: cannot 'minishell' while in 'minishell'\n"); //-> set imbrication level += 1, set SIGIGNORE until done
	return (err);
}

/**
 * brief : will exec the command
 * note : children either get execve'd here or get exit(-1) for failure to execve
 * if execve fails, frees everything and EXITS
 */
void	execve_command(t_command_exec *c, t_minishell *m, t_infos *i)
{
	int		err;

	err = execve_cmdpath(c, m);
	free_t_command_exec(&c);
	free_t_minishell(&m);
	free_t_infos(i);
	if (err)
		exit(err);
	exit(EXIT_SUCCESS);
}
