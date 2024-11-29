/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:03 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/29 04:40:04 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"
#include "../../../include/minishell.h"
#include "../../../include/utils.h"

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
 * 
 * brief: in char **tab : finds the ind of the line containing the char* if success.
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
		return (free(msg), ft_free_tab(env_paths), ft_error("error cmd\n", 127));
	}
	if (c->cmd_id != MINISHELL_ID)
	{ // CHANGE ME, pour l'instant : pas d'imbrications.
		if (set_signals_to_default() == -1)
			return (printerr("%s: %d: err\n", __FILE__, __LINE__));
		err = execve(cmd_path, c->cmd_args, m->env);
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
