/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:36:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/08 03:39:13 by anoukan          ###   ########.fr       */
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
	new->redir = ft_strdup(str); // Save either the symbol or target as it is
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
	t_redir			*redir_list;
	t_enum_redir	type;
	char			*input;

	redir_list = NULL;
	i = 0;
	while (in[i])
	{
		type = get_redir_type(in[i]);
		if (type != R_INVALID && in[i + 1])
		{
			if (ft_strlen(in[i]) <= 2)
				input = ft_strjoin(in[i], in[i + 1]);
			else
				input = ft_strdup(in[i]);
			if (!input)
				return (NULL);
			add_node(type, input, &redir_list);
			free(input);
		}
		i++;
	}
	return (redir_list);
}
// need to add a free after the null return if (!input)
