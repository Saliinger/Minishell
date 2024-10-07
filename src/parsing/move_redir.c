/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:36:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/08 01:22:51 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Helper function to add a new node to the redirection list
static void	add_node(t_enum_redir type, char *str, t_redir **head)
{
	t_redir	*new;
	t_redir	*temp;

	new = (t_redir *)malloc(sizeof(t_redir));
	if (!new)
		return ;
	new->redir = ft_strdup(str);
	new->type = type;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

// Function to identify the type of redirection based on symbols
static t_enum_redir	get_redir_type(char *str)
{
	if (!ft_strncmp(str, ">>", 2))
		return (R_OUT_APPEND);
	else if (!ft_strncmp(str, ">", 1))
		return (R_OUT_FILE);
	else if (!ft_strncmp(str, "<<", 2))
		return (R_IN_HD);
	else if (!ft_strncmp(str, "<", 1))
		return (R_IN_FILE);
	return (R_INVALID);
}

// Function to extract redirection symbols and targets from the input
t_redir	*extract_redir(char **in)
{
	int				i;
	t_enum_redir	type;
	t_redir			*redir_list;

	redir_list = NULL;
	i = 0;
	while (in[i])
	{
		if (!ft_strncmp(in[i], ">", 1) || !ft_strncmp(in[i], "<", 1))
		{
			type = get_redir_type(in[i]);
			if (type != R_INVALID && in[i + 1])
			{
				add_node(type, in[i + 1], &redir_list);
				i++;
			}
		}
		i++;
	}
	return (redir_list);
}
