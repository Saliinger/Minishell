/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/builtins/echo/ft_echo.c
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:00 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/09 11:40:10 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(t_minishell *minishell, t_command *command)
{
	return (0);
========
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/27 10:59:03 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	old_ft_exec(t_command *command, t_minishell *minishell)
{
	(void)minishell;
	// if (command->builtin == true)
	print_command(command);
	// 	builtin_slector(command, minishell);
	// else
	// 	ft_extern(command, minishell);
>>>>>>>> main:src/exec/OLD_EXEC/exec.c
}
