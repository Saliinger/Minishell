/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:09 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 13:34:38 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_exit(t_minishell *minishell, t_command_exec *command, bool fail)
{
    int exit_code;

	if (nbr_of_line(command->cmd_args) > 2)
		return (1);
    free_minishell(minishell);
	if (command->cmd_args[1] && fail == false)
    {
        exit_code = atoi(command->cmd_args[1]);
        //free_command(command);
        exit(exit_code);
    }
	else if (fail == true)
    {
        //free_command(command);
        exit(EXIT_FAILURE);
    }
	else
    {
        //free_command(command);
        exit(EXIT_SUCCESS);
    }
}
