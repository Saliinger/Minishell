/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:08 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/28 04:05:37 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_command *parsing(char *str, t_minishell *minishell)
{
	t_command	*current;
	t_command	*temp;

	current = command_init(str);
	temp = current;
	while (temp)
	{
		temp->clean_arg = clean_arg(temp->arg, minishell);
        if (temp->id != EXPAND_ID)
            temp->clean_arg = expand_in(temp->clean_arg, minishell);
        if (!temp->clean_arg)
            return (NULL); // need to add free command
		temp = temp->subcommand;
	}
	if (current)
        return(current);
	else
		printf("loli said: bitch it's not working\n");
	return (NULL);
}
