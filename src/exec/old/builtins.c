/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/11 15:33:08 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// execute builtins functions

#include "../../../include/minishell.h"

void	builtin_slector(t_command *command, t_minishell *minishell)
{
	if (command->id == ECHO_ID)
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
		exit_shell(minishell, false);
	else if (command->id == HD_ID)
		ft_heredoc(command, minishell);
	else if (command->id == EXPAND_ID)
		ft_heredoc(command, minishell);
	//if (command->pipe == false)
	//	free_command(command);
}
