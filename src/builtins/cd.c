/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:31:27 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd navigation
// issue it update the path even with an error
// need also to fix the env update
//
// gonna change everything soon usage of another method

#include "../../include/minishell.h"

void	ft_cd(t_command *command, t_minishell *minishell)
{
	int		error;
	char	*path;
	int		home_line;

	if (!command->arg[1] || ft_strncmp(command->arg[1], "~", 1) == 0)
	{
		home_line = get_env_var(minishell, "HOME=");
		if (!minishell->env[home_line])
			return (perror("HOME not set"));
		path = ft_strdup(minishell->env[home_line]); // path = HOME=* need to cut the home part
		free(minishell->old_pwd);
		minishell->old_pwd = ft_strdup(minishell->pwd);
		free(minishell->pwd);
		minishell->pwd = ft_strdup(path);
	}
	else
	{
		path = ft_strdup(command->arg[1]);
	}
	error = chdir(path);
	if (error == 0)
	{
		printf("Changed dir to %s\n", minishell->pwd);
		change_pwd(minishell);
	}
	else
		perror("Error changing directory");
}
