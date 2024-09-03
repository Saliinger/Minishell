#include "../../include/minishell.h"

void	ft_unset(t_minishell *minishell, t_command *command)
{
	char	**new_env;
	int		var_line;
	int		i;

	var_line = get_env_var(minishell, command->arg[1], ft_strlen(command->arg[1]));
	if (var_line == -1)
	{
		perror("Error\nThe var doesn't exist\n");
		return;
	}
}
