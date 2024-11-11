/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:09 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/09 11:40:51 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_minishell *minishell, t_command *command, bool fail)
{
	printf("Bye Bye Bye\n");
	free_minishell(minishell);
	if (nbr_of_line(command->arg) > 2)
		return ;
	else if (command->arg[1])
		exit(atoi(command->arg[1]) % 256);
	else if (fail == true)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
