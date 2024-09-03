#include "../../include/minishell.h"

// this function is use to delete existing var in env
// it can delete multiple var at the same time (gonna make it after the base works)
// to add the multiple var i am gonna use a *int to store all the existing var if one of them doesn't exist just return an error

void	ft_unset(t_command *command, t_minishell *minishell)
{
	char	**new_env;
	int		var_line;
	int		i;
	int		j;

	var_line = get_env_var(minishell, command->arg[1], ft_strlen(command->arg[1]));
	if (var_line == -1)
	{
		perror("Error\nThe var doesn't exist\n");
		return ;
	}
	new_env = (char **)malloc(sizeof(char ) * nbr_of_line((minishell->env) - 1));
	if (!new_env)
	{
		perror("Error\nCouldn't create the new env");
		return ;
	}
	j = 0;
	i = 0;
	while (minishell->env[i])
	{
		if (i != var_line)
		{
			new_env[j] = ft_strdup(minishell->env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	free_env(minishell->env);
	minishell->env = new_env;
}
