/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:08 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/22 23:16:12 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_command	*parsing(char *str, t_minishell *minishell)
{
	t_command	*current;
	t_command	*temp;

	// printf("str: %s\n", str);
	// if (!input_checker(str))
	//	return ;
	current = command_init(str);
	// ft_print(current->arg, 0);
	// if (current->subcommand)
	// 	ft_print(current->subcommand->arg, 0);
	temp = current;
	while (temp)
	{
		temp->clean_arg = clean_arg(temp->arg, minishell);
		temp = temp->subcommand;
	}
	if (current)
		return (current);
	else
	{
		printf("loli said: bitch it's not working\n");
		return (NULL);
	}
}

// it just create the node for the command and start the exec
