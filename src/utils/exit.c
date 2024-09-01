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

void	exit_shell(bool fail)
{
	printf("Bye Bye Bye\n");
	if (fail == true)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
