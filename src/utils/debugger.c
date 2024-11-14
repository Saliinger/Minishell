/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:53:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/14 02:24:50 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

static void	start(t_command *command)
{
	printf("\tCommand ID:   \t %d\n", command->id);
	printf("\tCommand:      \t %s\n", command->command);
	printf("\tBuilt-in:     \t %s\n", command->builtin ? "true" : "false");
	printf("\tHas Pipe:     \t %s\n", command->pipe ? "true" : "false");
	printf("\tPipe Position:\t %d\n", command->pipe_position);
	printf("\tPID:          \t %d\n", command->pid);
	printf("\tInfile FD:    \t %d\n", command->infile_fd);
	printf("\tOutfile FD:   \t %d\n", command->outfile_fd);
	printf("\tInput:        \t %s\n", command->in);
}

void	print_command(t_command *command)
{
	int	i;

	i = 0;
	printf("_____________t_command: %p_______________\n", command);
	start(command);
	if (command->arg)
	{
		printf("\tArguments:\n");
		while (command->arg[i])
		{
			printf("\t\tArg[%d]:\t %s\n", i, command->arg[i]);
			i++;
		}
		printf("\t\tArg[%d]:\t %p\n", i, command->arg[i]);
	}
	else
		printf("\t%p\n", command->arg[i]);


	printf("\tCleaned Arguments:\n");
	if (command->clean_arg)
	{
		i = 0;
		while (command->clean_arg[i])
		{
			printf("\t\tClean Arg[%d]:\t %s\n", i, command->clean_arg[i]);
			i++;
		}
		printf("\t\tClean Arg[%d]:\t %p\n", i, command->clean_arg[i]);
	}
	else
		printf("\t%p\n", command->clean_arg);

	printf("\tRedirection:\n");
	if (command->redirection)
		print_redirs(command->redirection);
	else
		printf("\t%p\n", command->redirection);

	printf("\tPipe FDs: [%d, %d]\n", command->pipe_fds[0], command->pipe_fds[1]);

	printf("\tSubcommand:");
	printf("\t%p\n\n", command->subcommand);
	if (command->subcommand)
		print_command(command->subcommand);
}
