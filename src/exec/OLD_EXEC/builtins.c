/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 17:29:35 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// execute builtins functions

#include "../../../include/minishell.h"

void	builtin_slector(t_command *command, t_minishell *minishell)
{
	/*if (command->id == ECHO_ID)
		ft_echo(minishell, command);
	else if (command->id == CD_ID)
		ft_cd(command, minishell);
	else if (command->id == PWD_ID)
		ft_pwd(minishell);
	else if (command->id == EXPORT_ID)
		ft_export(command, minishell);
	else if (command->id == UNSET_ID)
		ft_unset(command, minishell);
	else if (command->id == ENV_ID)
		ft_env(minishell);
	else if (command->id == EXIT_ID)
		exit_shell(minishell, command, false);
	else if (command->id == HD_ID)
		ft_heredoc(command, minishell);
	else if (command->id == EXPAND_ID)
		ft_expand(command, minishell);*/
	(void) command;
	(void) minishell;
}
