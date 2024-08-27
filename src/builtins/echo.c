/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:32:36 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// echo command + option -n
// carefull with space and multiple time the same option

#include "../../include/minishell.h"
#include <stdio.h>

static int	flag(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == 'n')
			flag++;
		i++;
	}
	return (flag);
}

void	ft_echo(t_command *command)
{
	if (flag(command->in) > 0)
		printf("%s", command->in);
	else
		printf("%s\n", command->in);
	printf("\n");
	ft_print(command->arg);
}
