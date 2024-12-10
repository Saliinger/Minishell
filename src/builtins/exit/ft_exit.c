/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:09 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/10 15:39:56 by anoukan          ###   ########.fr       */
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

static int	ft_exit_extend(int exit_code, t_minishell *minishell, t_command_exec *cmd)
{
	free_minishell(minishell);
	free_t_command_exec(&cmd);
	exit(exit_code);
}

int	ft_exit(t_minishell *minishell, t_command_exec *command, bool fail)
{
	if (nbr_of_line(command->cmd_args) >= 3)
	{
		printerr("bash: exit: too many arguments\n");
		exit(1);
	}
	if (nbr_of_line(command->cmd_args) == 2
		&& check_arg(command->cmd_args[1]) == true)
	{
		printerr(" numeric argument required\n");
		ft_exit_extend(255, minishell, command);
	}
	else if (command->cmd_args[1] && fail == false)
		ft_exit_extend(atoi(command->cmd_args[1]), minishell, command);
	else if (fail == true)
		ft_exit_extend(EXIT_FAILURE, minishell, command);
	else
		ft_exit_extend(EXIT_SUCCESS, minishell, command);
}

// add error 255 if word as arg if 3 arg return 1