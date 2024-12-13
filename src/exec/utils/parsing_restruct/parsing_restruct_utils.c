/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_restruct_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:36:14 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:48:26 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

/**
 * brief: frees a linked list of redirections
 **/
void	free_redirections(t_redir *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		free(tmp->redir);
		free(tmp);
	}
}

/**
 * brief : frees a t_command_exec node, including its dynamically 
 * 															allocated fields
 * 
 */
void	free_command_exec_node(t_command_exec *node)
{
	int	i;

	if (!node)
		return ;
	if (node->cmd_args)
	{
		i = 0;
		while (node->cmd_args[i])
		{
			free(node->cmd_args[i]);
			i++;
		}
		free(node->cmd_args);
	}
	free_redirections(node->redir_files_llist);
	free(node);
}

/**
 * brief: frees an entire t_command_exec linked list
 * 
 */
void	free_command_exec_list(t_command_exec *head)
{
	t_command_exec	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free_command_exec_node(tmp);
	}
}

t_command_exec	*allocate_t_command_exec_node(void)
{
	t_command_exec	*c;

	c = malloc(sizeof(t_command_exec));
	if (!c)
		return (NULL);
	c->cmd_args = NULL;
	c->cmd_id = -1;
	c->redir_files_llist = NULL;
	c->redir_fds[0] = -1;
	c->redir_fds[1] = -1;
	c->last_heredoc_str = NULL;
	c->next = NULL;
	return (c);
}

t_redir	*allocate_redir_node(t_redir *old)
{
	t_redir	*new_node;

	new_node = malloc(sizeof(t_redir));
	if (!new_node)
		return (NULL);
	new_node->redir = strdup(old->redir);
	if (!new_node->redir)
	{
		free(new_node);
		return (NULL);
	}
	new_node->type = old->type;
	new_node->next = NULL;
	return (new_node);
}
