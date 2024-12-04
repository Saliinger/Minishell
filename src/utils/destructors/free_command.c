/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:35:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 17:25:10 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function will free command at the end of use

#include "../../../include/minishell.h"

static void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

static void	free_redir(t_redir *head)
{
	t_redir	*next;

	next = head;
	while (head)
	{
		free(head->redir);
		free(head);
		head = next;
	}
}

void	free_command(t_command *command)
{
	if (!command)
		return ;
    if (command->command)
        free(command->command);
    if (command->in)
		free(command->in);
	if (command->arg)
		free_arg(command->arg);
    if (command->clean_arg)
        free_arg(command->clean_arg);
    if (command->redirection)
        free_redir(command->redirection);
    if (command->subcommand)
		free_command(command->subcommand);
    free(command);
}

