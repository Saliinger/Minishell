/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/07 16:15:06 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// echo command + option -n
//
// need to add the print of env and hidden env

#include "../../include/minishell.h"

static bool	flag_endl(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-' && arg[i][1] == 'n' && ft_strlen(arg[i]) == 2)
			return (true);
		if (arg[i][0] != '-')
			return (false);
		i++;
	}
	return (false);
}

static void	ft_print_echo(char **arg, int i)
{
	while (arg[i])
	{
		printf("%s", arg[i]);
		if (arg[i + 1])
			printf(" ");
		i++;
	}
	if (flag_endl(arg) != true)
		printf("\n");
}

static int	flag_num(char **arg)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-')
			flag++;
		if (arg[i][0] != '-')
			return (flag);
		i++;
	}
	return (flag);
}

void	ft_echo(t_command *command)
{
	int	flag;

	flag = flag_num(command->arg);
	ft_print_echo(command->arg, flag);
}
