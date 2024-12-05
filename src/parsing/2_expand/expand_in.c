#include "../../../include/minishell.h"

int get_var_name(char *arg)
{
    int len = 0;

    if (arg[len] == '$')
        len++;
    while (arg[len] && (ft_isalpha(arg[len]) || ft_isdigit(arg[len]) || arg[len] == '_'))
        len++;
    return (len);
}

static char	*expanded(t_minishell *minishell, char *var, int *start, char *new_arg)
{
    char *res;
    char *var_name;
    char *extend;
    int var_name_len;
    int line;
    int k = 0;

    var_name_len = get_var_name(var + *start) - 1;
    var_name = (char *)malloc(sizeof(char) * (var_name_len + 1));
    if (!var_name)
        return (NULL);
    ft_strlcpy(var_name, var + *start + 1, var_name_len + 1);
    line = get_env_var(minishell, var_name, var_name_len);
    free(var_name);

    if (line == -1)
    {
        res = ft_strdup("");
        while (*start > k)
        {
            res = add_char(res, var[k]);
            k++;
        }
        *start += var_name_len + 1;
        return (res);
    }
    extend = minishell->env[line] + var_name_len + 1;
    res = ft_strdup("");
    if (!new_arg) {
        while (*start > k) {
            res = add_char(res, var[k]);
            k++;
        }
    } else {
        while (new_arg[k]) {
            res = add_char(res, new_arg[k]);
            k++;
        }
        free(new_arg);
    }
    k = 0;
    while (extend[k])
    {
        res = add_char(res, extend[k]);
        k++;
    }
    *start += var_name_len + 1;
    return (res);
}

static int in_quote(int status, char type)
{
    if (type == '\"' && status == 0)
        return (1);
    else if (type == '\'' && status == 0)
        return (-1);
    else if ((type == '\"' && status == 1) || (type == '\'' && status == -1))
        return (0);
    return (status);
}

char	**expand_in(char **arg, t_minishell *minishell)
{
    int		i;
    int		j;
    int		status;
    char	**new_arg;

    new_arg = (char **)malloc(sizeof(char *) * (nbr_of_line(arg) + 1));
    if (!new_arg)
        return (NULL);
    i = 0;
    while (arg[i])
    {
        j = 0;
        status = 0;
        new_arg[i] = NULL;
        while (arg[i][j])
        {
            if (arg[i][j] == '\"' || arg[i][j] == '\'')
            {
                if (!new_arg[i])
                    new_arg[i] = ft_strdup("");
                if (!new_arg[i])
                    return (free_env(new_arg), NULL);
                status = in_quote(status, arg[i][j]);
                new_arg[i] = add_char(new_arg[i], arg[i][j]);
                if (!new_arg[i])
                    return (free_env(new_arg), NULL);
                j++;
            }
            else if (arg[i][j] == '$' && status >= 0)
            {
                new_arg[i] = expanded(minishell, arg[i], &j, new_arg[i]);
                if (!new_arg[i])
                    return (free_env(new_arg), NULL);
            }
            else
            {
                if (!new_arg[i])
                    new_arg[i] = ft_strdup("");
                if (!new_arg[i])
                    return (free_env(new_arg), NULL);
                new_arg[i] = add_char(new_arg[i], arg[i][j]);
                if (!new_arg[i])
                    return (free_env(new_arg), NULL);
                j++;
            }
        }
        i++;
    }
    new_arg[i] = NULL;
    free_env(arg);
    return (new_arg);
}
