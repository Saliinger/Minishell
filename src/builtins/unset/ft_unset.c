/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:26 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/06 23:00:56 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_unset(t_command_exec *command, t_minishell *minishell)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	if (nbr_of_line(command->cmd_args) > 1)
	{
		while (command->cmd_args[i])
		{
			line = get_env_var(minishell, command->cmd_args[i],
					ft_strlen(command->cmd_args[i]));
			if (line != -1)
			{
				delete_var(minishell, line);
				delete_export_node(minishell->exportList, command->cmd_args[i]);
			}
			i++;
		}
	}
	return (0);
}
