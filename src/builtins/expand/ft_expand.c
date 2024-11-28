/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:13 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 01:44:17 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// need to print the env var

int	ft_expand(t_command_exec *command, t_minishell *minishell)
{
	char	*cmd_args;
	int		g;
	int		len;
	int		line;

	cmd_args = command->cmd_args[0];
	cmd_args++;
	len = ft_strlen(command->cmd_args[0]);
	line = get_env_var(minishell, cmd_args, len - 1);
	if (line >= 0)
	{
		g = 0;
		while (minishell->env[line][g] != '=')
			g++;
		g++;
		while (minishell->env[line][g])
		{
			ft_putchar_fd(minishell->env[line][g], 1);
			g++;
		}
	}
	ft_putchar_fd('\n', 1);
	return (0);
}
