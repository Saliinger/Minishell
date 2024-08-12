// display env variable

#include "../../include/minishell.h"

void    ft_env(t_minishell *minishell)
{
    int i = 0;

    while (minishell->env[i])
    {
        printf("%s\n", minishell->env[i]);
        i++;
    }
}