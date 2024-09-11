/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/11 15:33:14 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	old_ft_exec(t_command *command, t_minishell *minishell)
{
	if (command->builtin == true)
		builtin_slector(command, minishell);
	else
		ft_extern(command, minishell);
}
