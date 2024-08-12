// execute builtins functions

#include "../../include/minishell.h"
#include <stdbool.h>

void	builtin_slector(t_command *command, t_minishell *minishell)
{
	if (command->id == ECHO_ID)
		ft_echo(command);
	else if (command->id == CD_ID)
		printf("lol");
	else if (command->id == PWD_ID)
		ft_pwd();
	else if (command->id == EXPORT_ID)
		printf("lol");
	else if (command->id == UNSET_ID)
		printf("lol");
	else if (command->id == ENV_ID)
		ft_env(minishell);
	else if (command->id == EXIT_ID)
		exit_shell(false);
	if (command->pipe == false)
		free_command(command);
}
