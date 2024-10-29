/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/01 12:56:46 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd navigation
// issue it update the path even with an error
// need also to fix the env update
//
// gonna change everything soon usage of another method

#include "../../include/minishell.h"

static void	dup_home(char *current_home, char *res, int i)
{
	int	j;

	j = 0;
	while (current_home[i])
	{
		res[j] = current_home[i];
		i++;
		j++;
	}
	res[j] = '\0';
}

static char	*get_home(t_minishell *minishell)
{
	int		home_line;
	char	*current_home;
	int		i;
	char	*res;

	home_line = get_env_var(minishell, "HOME=", 5);
	if (!minishell->env[home_line])
		return (NULL);
	current_home = ft_strdup(minishell->env[home_line]);
	i = 0;
	while (current_home[i] && current_home[i] != '=')
		i++;
	if (current_home[i] == '=')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(current_home) - i) + 1);
	if (!res)
	{
		free(current_home);
		return (NULL);
	}
	dup_home(current_home, res, i);
	return (res);
}

void	ft_cd(t_command *command, t_minishell *minishell)
{
	int		error;
	char	*path;

	if (!command->arg[1] || ft_strncmp(command->arg[1], "~", 1) == 0)
	{
		path = get_home(minishell);
		if (!path)
		{
			perror("Home is not set");
			return ;
		}
		free(minishell->old_pwd);
		minishell->old_pwd = ft_strdup(minishell->pwd);
		free(minishell->pwd);
		minishell->pwd = ft_strdup(path);
	}
	else
		path = ft_strdup(command->arg[1]);
	error = chdir(path);
	if (error == 0)
	{
		printf("Changed dir to %s\n", path);
		change_pwd(minishell);
	}
	else
		perror("Error changing directory");
}

// add lstast for the symlink
