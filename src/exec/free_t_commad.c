/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_commad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:45:19 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/09 22:36:46 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

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
 * brief : for each node, frees the elements of the node of the linked list, then frees the node;
 *
 */
void	free_t_command(t_command *cmds)
{
	t_command	*tmp;

	tmp = cmds;
	while (cmds)
	{
		tmp = cmds->pipe_command;
		free_cmds_elems(cmds);
		free(cmds);
		cmds = tmp;
	}
	cmds = NULL;
}
