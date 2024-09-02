/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:03:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/02 11:12:55 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// export command can create new env and change the value of others

static void	create_value(t_minishell *minishell, char *var)
{
	int	i;
	char	**new_env;

	i = 0;
	new_env = (char **)malloc(sizeof(char *) * nbr_of_line(minishell->env) + 2);
	if (!new_env)
	{
		printf("Error\nFail malloc new_env\n");
		return ;
	}
	while (minishell->env[i])
	{
		new_env[i] = ft_strdup(minishell->env[i]);
		i++;
	}
	new_env[i] = ft_strdup(var);
	i++;
	new_env[i] = NULL;
	free_env(minishell->env);
	minishell->env = new_env;
}

static void	change_value(t_minishell *minishell, char *var)
{
	int	var_line;
	int	len;

	len = 0;
	while (var[len] != '=' && var[len])
		len++;
	var_line = get_env_var(minishell, var, len);
		printf("%d\n%d\n", len, var_line);
	if (var_line == -1)
	{
		create_value(minishell, var);
		return;
	}
	free(minishell->env[var_line]);
	minishell->env[var_line] = ft_strdup(var);
	if (!minishell->env[var_line])
	{
		printf("Error\nThe env variable didn't got set (Malloc)\n");
		return;
	}
	printf("%s\n", minishell->env[var_line]);
}



void	ft_export(t_command *command, t_minishell *minishell)
{
	char	*var;

	if (nbr_of_line(command->arg) == 2)
	{
		var = ft_strdup(command->arg[1]);
		change_value(minishell, var);
	}
	else
		printf("Error\nThere's too much options\n");
	if (var)
		free(var);
}
