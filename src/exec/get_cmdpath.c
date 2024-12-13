/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 04:28:04 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:22:48 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include <errno.h>

static char	*get_command(char **paths, char *cmd, int *err)
{
	int		i;
	char	*command;

	if (!paths)
		return (cmd);
	if (!cmd)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		command = ft_strjoin(paths[i], "/");
		if (!command)
			return (NULL);
		command = ft_strjoin_frees1(command, cmd);
		if (!command)
			return (NULL);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (printerr("%s: command not found\n", cmd), *err = 127, NULL);
}

/** 
 * 
 * brief: in char **tab : finds the ind of the line containing the char*.
 * -1 if failure.  
 **/
static int	tab_ind_line_containing(char **tab, char *containing)
{
	int		i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i] != NULL && ft_strncmp(containing, tab[i], 4))
		i++;
	if (tab[i] == NULL)
		return (-1);
	return (i);
}

/**
 * brief : returns tab of paths found in the env, 
 * if fails, returns NULL
 * 
 *  */
static char	**get_env_paths(t_minishell *m)
{
	int		i;
	char	*line_paths;
	char	**result;

	i = tab_ind_line_containing(m->env, "PATH");
	if (i < 0)
		return (NULL);
	line_paths = ft_substr(m->env[i], 5, ft_strlen(m->env[i]));
	result = ft_split(line_paths, ':');
	free(line_paths);
	if (result == NULL)
		return (NULL);
	return (result);
}

/**
 * brief : returns appropriate for or dir error if name is not executable.
 * 
 */
static char	*get_file_or_dir(char *name, int *err)
{
	struct stat	f;

	if (lstat(name, &f) == -1)
	{
		if (errno == ENOTDIR)
			*err = 126;
		else
			*err = 127;
		return (printerr("minishell: "), perror(name), NULL);
	}
	if (S_ISDIR(f.st_mode))
		return (printerr("minishell: %s: Is a directory\n", name), \
														*err = 126, NULL);
	return (name);
}

/**
 * brief : returns the path of the cmd to exec. checks for dir 
 * 							or file if starts with ./ or contains /, 
 * will display error correctly for valid cmd path not found.
 * if fails, returns NULL
 * 
 *  */
char	*get_cmd_path(char *cmd_name, t_minishell *m, int *err)
{
	char	**env_paths;
	char	*cmd_path;

	env_paths = get_env_paths(m);
	if (ft_strncmp(cmd_name, "./", 2) == EXIT_SUCCESS || \
												ft_strchr(cmd_name, '/'))
	{
		cmd_path = get_file_or_dir(cmd_name, err);
	}
	else if (cmd_name[0] == '.')
	{
		ft_free_tab(env_paths);
		return (printerr("%s: command not found\n", cmd_name), \
														*err = 127, NULL);
	}
	else
		cmd_path = get_command(env_paths, cmd_name, err);
	ft_free_tab(env_paths);
	return (cmd_path);
}
