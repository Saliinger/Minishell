// execute extern function

#include "../../include/minishell.h"

void	ft_extern(t_command *command, t_minishell *minishell)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = ft_strjoin_frees1(PATH, command->command);
	pid = fork();
	if (pid == 0)
		execve(path, command->arg, minishell->env);
	//if (command->pipe_command == false)

	waitpid(pid, &status, 0);
	free(path);
}
