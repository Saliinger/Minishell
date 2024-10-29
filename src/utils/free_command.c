/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:35:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:35:53 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function will free command at the end of use

#include "../../include/minishell.h"

static void	free_arg(t_command *command)
{
	int	i;

	i = 0;
	while (command->arg[i])
	{
		free(command->arg[i]);
		i++;
	}
	free(command->arg);
}

void	free_redir(t_redir *head)
{
	t_redir	*next;

	next = head;
	while (head)
	{
		free(head->redir);
		free(head);
		head = next;
	}
	if (next)
	{
		free(next->redir);
		free(next);
	}
}

void	free_command(t_command *command)
{
	if (!command)
		return ;
	if (command->in)
	{
		free(command->in);
		command->in = NULL;
	}
	if (command->arg)
		free_arg(command);
	if (command->subcommand)
	{
		free_command(command->subcommand);
		command->subcommand = NULL;
	}
	free(command);
	command = NULL;
}
