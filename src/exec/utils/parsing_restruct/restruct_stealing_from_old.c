/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restruct_stealing_from_old.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:30:18 by ekrebs            #+#    #+#             */
/*   Updated: 2024/10/31 22:14:39 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

/**
 * brief : allocates a c.
 * 
 * fields init with :
 * 	c->cmd_args 			= NULL;
 *	c->cmd_id 				= -1;
 *	c->redir_files_llist	= NULL;
 *	c->pipe_fds[0] 			= -1;
 *	c->pipe_fds[1] 			= -1;
 *	c->redir_fds[0] 		= -1;
 *	c->redir_fds[1] 		= -1;
 *	c->last_heredoc_str 	= NULL;
 *	c->next 				= NULL;
 * 
 */
static t_command_exec *allocate_t_command_exec_node(void)
{
	t_command_exec *c;

	c = malloc (sizeof(t_command_exec));
	if (!c)
		return (NULL);
	c->cmd_args = NULL;
	c->cmd_id = -1;
	c->redir_files_llist = NULL;
	c->pipe_fds[0] = -1;
	c->pipe_fds[1] = -1;
	c->redir_fds[0] = -1;
	c->redir_fds[1] = -1;
	c->last_heredoc_str = NULL;
	c->next = NULL;
	return (c);
}

/**
 * 
 * brief : steals the useful data fields address from old to c.
 * 
 */
static void steal_data_addr(t_command *old, t_command_exec *c)
{
	c->cmd_id = old->id;
	if (old->id == -1)
		c->cmd_id = 0;
	c->cmd_args = old->clean_arg;
	c->redir_files_llist = old->redirection;
}

/**
 * 
 * brief : for each node in old : steals the address of the useful data fields in old, copies the addresses to the data fields in c.
 * 
 */
int	restruct_stealing_from_old(t_command **old, t_command_exec **c)
{
	t_command *tmp;
	t_command_exec *new;

	if (!old || !*old)
		return (EXIT_SUCCESS);
	new = allocate_t_command_exec_node();
	if (!new || !c)
		return (free_t_command(old), ERR);
	*c = new;
	while (*old)
	{
		tmp = (*old)->subcommand;
		steal_data_addr(*old, new);
		*old = tmp;
		if (*old)
		{
			new->next = allocate_t_command_exec_node();
			if (!new->next)
				return (free_t_command(old), free_t_command_exec(c), ERR);
			new = new->next;
		}
	}
	new->next = NULL;
	return (EXIT_SUCCESS);
}
