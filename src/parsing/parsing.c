/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:08 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/07 22:33:21 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parsing(char *str, t_minishell *minishell)
{
	t_command	*current;

	// printf("str: %s\n", str);
	// if (!input_checker(str))
	//	return ;
	current = command_init(str);
	// ft_print(current->arg, 0);
	// if (current->subcommand)
	// 	ft_print(current->subcommand->arg, 0);
	current->clean_arg = clean_arg(current->arg, minishell);
	if (current)
		old_ft_exec(current, minishell);
	else
		printf("loli said: bitch it's not working\n");
}

// it just create the node for the command and start the exec
