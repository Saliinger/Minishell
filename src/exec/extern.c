// execute extern function

#include "../../include/minishell.h"

void	ft_extern(t_command *command, t_minishell *minishell)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = ft_strjoin(PATH, command->command);
	pid = fork();
	if (pid == 0)
		execve(path, command->arg, minishell->env);

	waitpid(pid, &status, 0);
	//if (command->pipe == true)
	free_command(command);
	free(path);
}
