/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:53:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 00:03:23 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	print_redir(t_redir *redir)
// {
// 	int	i;

// 	i = 0;
// 	while (redir)
// 	{
// 		//printf("Redirection Node %d:\n", i);
// 		printf("\t%s  -  ", redir->redir);
// 		if (redir->type == R_IN_FILE)
// 			printf("R_IN_FILE\n");
// 		else if(redir->type == R_IN_HD)
// 			printf("R_IN_HD\n");
// 		else if(redir->type == R_OUT_FILE)
// 			printf("R_OUT_FILE\n");
// 		else if(redir->type == R_OUT_APPEND)
// 			printf("R_OUT_APPEND\n");
		
// 		redir = redir->next;
// 		i++;
// 	}
// }

static void	start(t_command *command)
{
	printf("\tInput:     \t%s\n", command->in);
	printf("\tCommand:   \t%s\n", command->command);
	printf("\tCommand ID:\t%d\n", command->id);
	//printf("\tBuilt-in: %s\n", command->builtin ? "true" : "false");
	//printf("\tHas Pipe: %s\n", command->pipe ? "true" : "false");
	//printf("\tPipe Position: %d\n", command->pipe_position);
	//printf("\tPID: %d\n", command->pid);
	//printf("\tInfile FD: %d\n", command->infile_fd);
	//printf("\tOutfile FD: %d\n", command->outfile_fd);
}

void	print_command(t_command *command)
{
	int	i;

	i = 0;
	printf("\n\n__________________t_command:__________________\n");
	start(command);
	if (command->arg)
	{
		printf("\tArguments_tokens_RAW:\n");
		while (command->arg[i])
		{
			printf("\t\t[%d]:\t%s\n", i, command->arg[i]);
			i++;
		}
	}
	if (command->clean_arg)
	{
		i = 0;
		printf("\tCleaned Arguments (execve tab):\n");
		while (command->clean_arg[i])
		{
			printf("\t\t[%d]:\t%s\n", i, command->clean_arg[i]);
			i++;
		}
	}
	if (command->redirection)
	{
		printf("\tRedirection:\n");
		print_redir(command->redirection);
	}
	//printf("\tPipe FDs: [%d, %d]\n", command->pipe_fds[0], command->pipe_fds[1]);
	if (command->subcommand)
	{
		//printf("----------Subcommand:-------------\n");
		print_command(command->subcommand);
	}
}

