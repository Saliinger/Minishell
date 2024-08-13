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

void	free_command(t_command *command)
{
    if (!command)
        return ;
	if (command->in) {
        free(command->in);
        command->in = NULL;
    }
	if (command->arg) {
        free_arg(command);
        //command->arg = NULL;
    }
	if (command->pipe_command) {
        free_command(command->pipe_command);
        command->pipe_command = NULL;
    }
	free(command);
    command = NULL;
}
