#include "../../include/minishell.h"

// need to print the env var

void	ft_expand(t_command *command, t_minishell *minishell)
{
	if (command->arg[0])
		printf("%s", minishell->env[get_env_var(minishell, command->arg[0], ft_strlen(command->arg[0]))]);
}

// only display the first path
