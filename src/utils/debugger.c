/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:53:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/10 15:37:21 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_redir(t_redir *redir)
{
	int	i;

	i = 0;
	while (redir)
	{
		printf("Redirection Node %d:\n", i);
		printf("  Type: %d\n", redir->type);
		printf("  Redir: %s\n", redir->redir);
		redir = redir->next;
		i++;
	}
}

static void	start(t_command *command)
{
	printf("Command ID: %d\n", command->id);
	printf("Command: %s\n", command->command);
	printf("Built-in: %s\n", command->builtin ? "true" : "false");
	printf("Has Pipe: %s\n", command->pipe ? "true" : "false");
	printf("Pipe Position: %d\n", command->pipe_position);
	printf("PID: %d\n", command->pid);
	printf("Infile FD: %d\n", command->infile_fd);
	printf("Outfile FD: %d\n", command->outfile_fd);
	printf("Input: %s\n", command->in);
}

void	print_command(t_command *command)
{
	int	i;

	i = 0;
	start(command);
	if (command->arg)
	{
		printf("Arguments:\n");
		while (command->arg[i])
		{
			printf("  Arg[%d]: %s\n", i, command->arg[i]);
			i++;
		}
	}
	if (command->clean_arg)
	{
		i = 0;
		printf("Cleaned Arguments:\n");
		while (command->clean_arg[i])
		{
			printf("  Clean Arg[%d]: %s\n", i, command->clean_arg[i]);
			i++;
		}
	}
	if (command->redirection)
	{
		printf("Redirection:\n");
		print_redir(command->redirection);
	}
	printf("Pipe FDs: [%d, %d]\n", command->pipe_fds[0], command->pipe_fds[1]);
	if (command->subcommand)
	{
		printf("Subcommand:\n");
		print_command(command->subcommand);
	}
}
