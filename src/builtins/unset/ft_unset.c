/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:26 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 01:43:53 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	**new_env(char **current_env, int var_line)
{
	int		i;
	int		j;
	char	**new_env;

	new_env = (char **)malloc(sizeof(char) * nbr_of_line((current_env)-1));
	if (!new_env)
		return (NULL);
	i = 0;
	j = 0;
	while (current_env[i])
	{
		if (i != var_line)
		{
			new_env[j] = ft_strdup(current_env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

static void	delete_value(t_minishell *minishell, char *var, int var_line)
{
	(void)var;
	if (var_line == -1)
	{
		perror("Error\nThe var doesn't exist\n");
		return ;
	}
	free_env(minishell->env);
	minishell->env = new_env(minishell->env, var_line);
}

int	ft_unset(t_command_exec *command, t_minishell *minishell)
{
	int	i;

	i = 1;
	if (nbr_of_line(command->cmd_args) >= 2)
	{
		while (command->cmd_args[i])
		{
			delete_value(minishell, command->cmd_args[i], get_env_var(minishell,
					command->cmd_args[i], ft_strlen(command->cmd_args[i])));
			i++;
		}
	}
	if (!minishell->env)
	{
		perror("Error\nThe new env is messed up!\n");
		return (1);
	}
	return (0);
}

// add check for the value that has been unset
// on line 71 add if 
