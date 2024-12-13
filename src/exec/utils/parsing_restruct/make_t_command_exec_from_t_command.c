/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_t_command_exec_from_t_command.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:31:11 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:50:55 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

static	t_redir	*copy_redirections(t_redir *old)
{
	t_redir	*head;
	t_redir	*prev;
	t_redir	*new_node;

	head = NULL;
	prev = NULL;
	while (old)
	{
		new_node = allocate_redir_node(old);
		if (!new_node)
		{
			free_redirections(head);
			return (NULL);
		}
		if (prev)
			prev->next = new_node;
		else
			head = new_node;
		prev = new_node;
		old = old->next;
	}
	return (head);
}

static int	copy_command_args(char **old_args, char ***new_args)
{
	int	i;

	i = 0;
	while (old_args[i])
		i++;
	*new_args = malloc((i + 1) * sizeof(char *));
	if (!*new_args)
		return (ERR);
	i = 0;
	while (old_args[i])
	{
		(*new_args)[i] = strdup(old_args[i]);
		if (!(*new_args)[i])
		{
			while (--i >= 0)
				free((*new_args)[i]);
			free(*new_args);
			return (ERR);
		}
		i++;
	}
	(*new_args)[i] = NULL;
	return (EXIT_SUCCESS);
}

static int	copy_old_data(t_command *old, t_command_exec *new)
{
	if (old->id == -1)
		new->cmd_id = 0;
	else
		new->cmd_id = old->id;
	if (copy_command_args(old->clean_arg, &new->cmd_args) != EXIT_SUCCESS)
		return (ERR);
	new->redir_files_llist = copy_redirections(old->redirection);
	if (old->redirection && !new->redir_files_llist)
	{
		free_command_exec_node(new);
		return (ERR);
	}
	return (EXIT_SUCCESS);
}

static	t_command_exec	*create_and_copy_node(t_command *old, \
													t_command_exec *head)
{
	t_command_exec	*new_node;

	new_node = allocate_t_command_exec_node();
	if (!new_node)
	{
		free_command_exec_list(head);
		return (NULL);
	}
	if (copy_old_data(old, new_node) != EXIT_SUCCESS)
	{
		free_command_exec_node(new_node);
		free_command_exec_list(head);
		return (NULL);
	}
	return (new_node);
}

/**
 * brief : makes the t_command_exec by duplicating the 
 * 											data fields of the t_command *old.
 * I'm doing this because I'm not sure why the t_command fields seemed
 * 	to leak new after I did my old method 
 * (stealing the dresses of the intresting data fields, 
 *  freeing the rest, replacing them by NULL to be sure I freed them.)
 * this way I'm assured if the resulting leaks are marked as comming from here,
 * they are mine. else, they are a parsing issue.
 */
int	make_t_command_exec_from_t_command(t_command *old, t_command_exec **new)
{
	t_command_exec	*head;
	t_command_exec	*prev;
	t_command_exec	*tmp;

	prev = NULL;
	head = NULL;
	while (old)
	{
		tmp = create_and_copy_node(old, head);
		if (!tmp)
			return (ERR);
		if (prev)
			prev->next = tmp;
		else
			head = tmp;
		prev = tmp;
		old = old->subcommand;
	}
	*new = head;
	return (EXIT_SUCCESS);
}
