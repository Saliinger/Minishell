//
// Created by anoukan on 03/12/24.
//

#include "../../include/minishell.h"

char    **remove_quote(char **arg)
{
    int i;
    int j;
    int k;
    char **res;

    res = (char **)malloc(sizeof(char *) * nbr_of_line(arg) + 1);
    if (!res)
        (NULL);
    i = 0;
    while (arg[i])
    {
        j = 0;
        k = 0;
        res[i] = (char *)malloc(sizeof(char) + ft_strlen(arg[i]) + 1);
        if (!res[i])
            (free_env(res), free_env(arg), NULL);
        while (arg[i][j])
        {
            if (arg[i][j] == '\'')
            {
                j++;
                while (arg[i][j] && arg[i][j] != '\'')
                {
                    res[i][k] = arg[i][j];
                    k++;
                    j++;
                }
                if (arg[i][j] == '\'')
                    j++;
            }
            else if (arg[i][j] == '\"')
            {
                j++;
                while (arg[i][j] && arg[i][j] != '\"')
                {
                    res[i][k] = arg[i][j];
                    k++;
                    j++;
                }
                if (arg[i][j] == '\"')
                    j++;
            }
            else
            {
                res[i][k] = arg[i][j];
                k++;
                j++;
            }
        }
        i++;
    }
    free_env(arg);
    res[i] = NULL;
    return (res);
}