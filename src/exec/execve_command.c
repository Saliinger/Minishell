/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:03 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/14 01:39:07 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : for each path in paths, will try to joind path and cmd, to get the cmdpath,
 * if the cmdpath is executable, returns it, else continues to search 
 * returns NULL if none found;
 */
static char	*get_accessible_command_path(char **paths, char *cmd)
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

static int	tab_ind_line_containing(char **tab, char *containing)
{
	int		i;

	i = 0;
	while (tab[i] != NULL && ft_strncmp(containing, tab[i], 4))
		i++;
	if (tab[i] == NULL)
		return (-1);
	return (i);
}

static char	**get_paths_from_env(char **env)
{
	int		i;
	char	*line_paths;
	char	**tab_paths;

	i = tab_ind_line_containing(env, "PATH");
	if (i == -1)
		return (NULL);
	if (i < 0)
		return (NULL);
	line_paths = ft_substr(env[i], 5, ft_strlen(env[i]));
	tab_paths = ft_split(line_paths, ':');
	free(line_paths);
	if (tab_paths == NULL)
		exit(ft_error("ft_split(paths, ':') = NULL\n", ERR_PARSE));
	return (tab_paths);
}

/**
 * brief : will exec the command (cmd located in c->cmd_args[0], args c->cmd_args, paths located in m->paths) 
 * 
 */
static int	execve_cmdpath(t_command_exec *c, t_minishell *m)
{
	int		err;
	char	**paths;
	char	*cmd_path;

	err = 0;
	paths = get_paths_from_env(m->env);
	cmd_path = get_accessible_command_path(paths, c->cmd_args[0]);
	ft_free_nullterm_tab(&paths);
	if (cmd_path == NULL)
	{
		dprintf(STDERR_FILENO, "%s: command not found\n", c->cmd_args[0]); //fix to printerr
		return (ERR);
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
	dprintf(STDERR_FILENO, "%s: %d: execve did not occur\n", __FILE__, __LINE__); //killme
	free_t_command_exec(&c);
	free_t_minishell(&m);
	free_pids(pids);
	if (err)
		exit(err);
	dprintf(STDERR_FILENO, "%s: %d: Oh hell no WTF\n", __FILE__, __LINE__); //killme
	exit(EXIT_SUCCESS);
}
