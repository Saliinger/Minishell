#include "../../../include/minishell.h"

char **remove_env(char **env, int to_delete)
{
    char **res;
    int len;
    int i = 0;
    int j = 0;

    len = nbr_of_line(env) - 1;
    res = (char **)malloc(sizeof(char *) * len + 1);
    if (!res)
        return (NULL);
    while (env[j])
    {
        if (j == to_delete)
            j++;
        else
        {
            res[i] = env[j];
            i++;
            j++;
        }
    }
    res[i] = NULL;
    free_env(env);
    return (res);
}

char **add_env(char **env, char *to_add)
{
    char **res;
    int len;
    int i = 0;

    len = nbr_of_line(env) + 1;
    res = (char **)malloc(sizeof(char *) * len + 1);
    if (!res)
        return (NULL);
    while (env[i])
    {
        res[i] = env[i];
        i++;
    }
    if (to_add)
    {
        res[i] = ft_strdup(to_add);
        free(to_add);
        i++;
    }
    res[i] = NULL;
    free_env(env);
    return (res);
}

int create_var(t_minishell *minishell, char *var)
{
    minishell->env = add_env(minishell->env, var);
    if (!minishell->env)
        return (1);
    return (0);
}

int delete_var(t_minishell *minishell, char *var)
{
    int line;
    char *temp;
    int temp_len;

    temp = var;
    temp_len = ft_strlen(var);
    line = get_env_var(minishell, temp, temp_len);
    minishell->env = remove_env(minishell->env, line);
    if (!minishell->env)
        return (1);
    return (0);
}
