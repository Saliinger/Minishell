#include "../../include/minishell.h"

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