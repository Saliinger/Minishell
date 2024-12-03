/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:08 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/01 19:44:08 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_command	*parsing(char *str, t_minishell *minishell)
{
	t_command	*current;
	t_command	*temp;

	current = command_init(str);
	temp = current;
	while (temp)
	{
		temp->clean_arg = clean_arg(temp->arg, minishell);
        temp->clean_arg = expand_in(temp->clean_arg, minishell);
		if (!temp->clean_arg)
			return (NULL);
		temp = temp->subcommand;
	}
    printf("\ncmd: %s\n", current->clean_arg[0]);
    if (current)
        return (current);
    return (NULL);
}

// need to add free command for l28
