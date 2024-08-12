#include "../../include/minishell.h"

void	ft_exec(t_command *command, t_minishell *minishell)
{
	if (command->builtin == true)
		builtin_slector(command, minishell);
	else
		ft_extern(command, minishell);
}
