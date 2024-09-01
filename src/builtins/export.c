/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:03:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/01 18:05:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// export command can create new env and change the value of others

static void	change_value(t_minishell *minishell, char *var)
{
	int	var_line;
	int	len;

	while (var[len] && var[len] != '=')
		len++;
	var_line = get_env_var(minishell, var, len);
	if (var_line == -1 || !minishell->env[var_line])
	{
		printf("Error\nThe env variable doesn't exist\n");
		return;
	}
	free(minishell->env[var_line]);
	minishell->env[var_line] = ft_strdup(var);
	if (!minishell->env[var_line])
	{
		printf("Error\nThe env variable didn't got set\n");
		return;
	}
}



void	ft_export(t_command *command, t_minishell *minishell)
{
	
}
