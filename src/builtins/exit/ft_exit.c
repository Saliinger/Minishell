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
	printf("Bye Bye Bye\n");
	if (nbr_of_line(command->cmd_args) > 2)
		return (1);
	free_minishell(minishell);
	if (command->cmd_args[1] && fail == false)
		exit(atoi(command->cmd_args[1]) % 256);
	else if (fail == true)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
