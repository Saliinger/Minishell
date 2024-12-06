#include "../../include/minishell.h"

char *get_name_env(char *var)
{
    int i = 0;
    char *name;

    while (var[i] && var[i] != '=')
        i++;
    if (var[i] == '=')
        i++;
    if (i == ft_strlen(var))
        return (ft_strdup(var));
    name = (char *) malloc(sizeof(char) * i + 1);
    if (!name)
        return (NULL);
    ft_strlcpy(name, var, i);
    printf("name: %s\n", name);
    return (name);
}

char *get_value_env(char *var)
{
    int i = 0;
    int len = 0;
    char *value;

    while (var[i] && var[i] != '=')
        i++;
    if (var[i] == '=')
        i++;
    len = ft_strlen(var) - i;
    if (len == 0)
        return (NULL);
    value = (char *) malloc(sizeof(char) * len + 1);
    if (!value)
        return (NULL);
    ft_strlcpy(value, var + i, len + 1);
    return (value);
}

t_export_list **init_export_list(char **env)
{
    int i = 0;
    t_export_list **init;

    init = (t_export_list **) malloc(sizeof(t_export_list));
    *init = NULL;
    while (env[i])
    {
        if (add_node_export(init, get_name_env(env[i]), get_value_env(env[i])) == 1)
            return(NULL); // add free export list
        i++;
    }
    return(init);
}
