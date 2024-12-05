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
        temp->arg = relexer(temp->arg);
        temp->redirection = extract_redir(temp->arg);
		temp->clean_arg = clean_arg(temp->arg, minishell);
        temp->clean_arg = expand_in(temp->clean_arg, minishell);
        temp->clean_arg = remove_quote(temp->clean_arg);
		if (!temp->clean_arg || !temp->arg)
			return (free_command(current) , NULL);
        ft_print(temp->clean_arg, 0);
		temp = temp->subcommand;
	}
    return (current);
}

// need to add free command for l28
