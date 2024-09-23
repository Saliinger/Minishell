/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_commad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:45:19 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/23 00:05:36 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/**
 * brief : frees the elements of the node
 * 
 */
static void	free_cmds_elems(t_command *cmds)
{
	free(cmds->in);
	free(cmds->command);
	free_nullterm_tab(cmds->arg);
}

/**
 * in : c is &cmds, where cmds is a t_command *cmds
 * brief : for each node, frees the elements of the node of the linked list, then frees the node;
 * sets the cmds to NULL
 * 
 */
void	free_t_command(t_command **c)
{
	t_command	*cmds;
	t_command	*tmp;

	cmds = *c;
	tmp = cmds;
	while (cmds)
	{
		tmp = cmds->subcommand;
		free_cmds_elems(cmds);
		free(cmds);
		cmds = tmp;
	}
	*c = NULL;
}
