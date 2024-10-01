/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:14 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/01 22:58:05 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_shell(t_minishell *minishell, t_command *command, bool fail)
{
	printf("Bye Bye Bye\n");
	free_minishell(minishell);
	if (nbr_of_line(command->arg) > 2)
		return;
	else if (command->arg[1])
	{
		exit(atoi(command->arg[1]) % 256);
	}
	else if (fail == true)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
