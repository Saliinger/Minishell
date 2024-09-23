#include "../../include/minishell.h"

// need to print the env var

void	ft_expand(t_command *command, t_minishell *minishell)
{

	int i = 0;

	while (command->arg[i])
	{
		printf("%s", minishell->env[get_env_var(minishell, command->arg[i], ft_strlen(command->arg[i]))]);
		i++;
	}
}
