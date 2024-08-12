#include "../../include/minishell.h"

bool	checker_command(char *in, char *command)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (in[i])
	{
		if (in[i] != command[j])
			break ;
		i++;
		j++;
	}
	if (i == ft_strlen(command))
		return (printf("command: %s\n", command), true);
	else
		return (false);
}

static int nbr_of_line(char **env)
{
    int i = 0;
    while (env[i])
        i++;
    return i;
}

char **get_env(char **env)
{
    int i = 0;
    char **res;

    if (!env)
        return NULL;
    res = (char **) malloc(sizeof(char *) * nbr_of_line(env) + 1);
    if (!res)
        return NULL;
    while (env[i])
    {
        res[i] = ft_strdup(env[i]);
        i++;
    }
    res[i] = NULL;
    return res;
}
