#include "../../../include/minishell.h"
#include <string.h>
#include <time.h>

int	get_env_var(t_minishell *minishell, char *var)
{
	int	i;

	i = 0;
	while (minishell->env[i])
	{
		if (strncmp(minishell->env[i], var, ft_strlen(var)))
			return (i);
		i++;
	}
	return (-1);	
}
