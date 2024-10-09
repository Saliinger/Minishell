#include "../../include/minishell.h"
#include <stdbool.h>
#include <stdio.h>

// Assuming ft_str and ft_print functions are already available for printing arrays and strings

void	print_redir(t_redir *redir)
{
	int	i;

	i = 0;
	while (redir)
	{
		printf("Redirection Node %d:\n", i);
		printf("  Type: %d\n", redir->type);
		// Assuming t_enum_redir has integer values
		printf("  Redir: %s\n", redir->redir);
		redir = redir->next;
		i++;
	}
}

void	print_command(t_command *command)
{
	int	i;

	i = 0;
	// Print basic command information
	printf("Command ID: %d\n", command->id);
	printf("Command: %s\n", command->command);
	printf("Built-in: %s\n", command->builtin ? "true" : "false");
	printf("Has Pipe: %s\n", command->pipe ? "true" : "false");
	printf("Pipe Position: %d\n", command->pipe_position);
	printf("PID: %d\n", command->pid);
	printf("Infile FD: %d\n", command->infile_fd);
	printf("Outfile FD: %d\n", command->outfile_fd);
	// Print the input string
	printf("Input: %s\n", command->in);
	// Print the argument array
	if (command->arg)
	{
		printf("Arguments:\n");
		while (command->arg[i])
		{
			printf("  Arg[%d]: %s\n", i, command->arg[i]);
			i++;
		}
	}
	// Print the cleaned argument array (if present)
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
	// Print redirection details
	if (command->redirection)
	{
		printf("Redirection:\n");
		print_redir(command->redirection);
	}
	// Print pipe file descriptors
	printf("Pipe FDs: [%d, %d]\n", command->pipe_fds[0], command->pipe_fds[1]);
	// Print subcommand (if present)
	if (command->subcommand)
	{
		printf("Subcommand:\n");
		print_command(command->subcommand); // Recursively print subcommand
	}
}
