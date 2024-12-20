/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_restruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:54:27 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:44:29 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 
 * brief : creates c from the data in old, old gets freed and set to NULL.
 * 
 * <=>
 * 
 * allocates the nodes for c, gets the useful info of 'old' to 'c'
 * frees the rest, and the node 'old'.
 * 
 * <=>
 * 
 * for each node in old : creates a respective c node, 
 * fills the data fields from 'c' with the usefull part of 
 * 												the date fields in 'old',
 * frees the useless ones in 'old', frees the struct 'old'
 * 
 * 
 */
int	parsing_restruct(t_command **old, t_command_exec **new)
{
	if (make_t_command_exec_from_t_command(*old, new) <= -1)
		return (dprintf(STDERR_FILENO, "minishell: %s: %s: %d: error.\n", \
										__FILE__, __FUNCTION__, __LINE__), ERR);
	free_command(*old);
	*old = NULL;
	index_nodes(*new);
	return (EXIT_SUCCESS);
}
