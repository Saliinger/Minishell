/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:26:14 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/26 16:26:24 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// need to print the env var

void	ft_expand(t_command *command, t_minishell *minishell)
{
	char *arg;
	int g;
	int len;
	int line;

	arg = command->arg[0];
	arg++;
	len = ft_strlen(command->arg[0]);
	line  = get_env_var(minishell, arg, len - 1);
	if (line >= 0)
	{
		g = 0;
		while(minishell->env[line][g] != '=')
			g++;
		g++;
		while(minishell->env[line][g])
		{
			ft_putchar_fd(minishell->env[line][g], 1);
			g++;
		}
	}
	ft_putchar_fd('\n', 1);
}

// only display the first path
