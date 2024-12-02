#include "../../../include/minishell.h"

bool check_var_equals(char *in)
{
    int nbr = 0;
    int i = 0;

    printf("in: %s\n", in);
    while (in[i] && in[i] != '\"')
    {
        if (in[i] == '=')
            nbr++;
        i++;
    }
    printf("nbr: %d\n", nbr);
    if (nbr == 0 || nbr > 1)
        return (false);
    else
        return (true);
}

bool check_var_name(char *in)
{
    int i = 0;

    if (ft_isalpha(in[i]) == 0 && in[i] != '_')
        return (false);
    else
        i++;
    while (in[i])
    {
        if (ft_isalpha(in[i]) == 0 && ft_isdigit(in[i]) == 0 && in[i] == '_')
            return (false);
        else
            i++;
    }
    return (true);
}

