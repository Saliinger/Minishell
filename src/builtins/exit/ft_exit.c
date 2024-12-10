/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:09 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/10 12:50:56 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static bool	check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalpha(s[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_exit(t_minishell *minishell, t_command_exec *command, bool fail)
{
	int	exit_code;

	if (nbr_of_line(command->cmd_args) >= 3)
	{
		printerr("bash: exit: too many arguments\n");
		exit(1);
	}
	free_minishell(minishell);
	if (nbr_of_line(command->cmd_args) == 2
		&& check_arg(command->cmd_args[1]) == true)
	{
		free_t_command_exec(&command);
		printerr(" numeric argument required\n");
		exit(255);
	}
	else if (command->cmd_args[1] && fail == false)
	{
		exit_code = atoi(command->cmd_args[1]);
		free_t_command_exec(&command);
		exit(exit_code);
	}
	else if (fail == true)
	{
		free_t_command_exec(&command);
		exit(EXIT_FAILURE);
	}
	else
	{
		free_t_command_exec(&command);
		exit(EXIT_SUCCESS);
	}
}

// add error 255 if word as arg if 3 arg return 1