#include "../../../include/minishell.h"

bool check_var_equals(char *in)
{
    int nbr = 0;
    int i = 0;

    while (in[i] && in[i] != '\"' && in[i] != '\'')
    {
        if (in[i] == '=')
            nbr++;
        i++;
    }
    if (nbr > 1 || nbr == 0)
        return (false);
    else
        return (printf("TRUE 1\n"), true);
}

bool check_var_name(char *in)
{
    int i = 0;

    if (!ft_isalpha(in[i]) || in[i] != '_')
        return (false);
    else
        i++;
    while (in[i] != '=')
    {
        if (!ft_isalpha(in[i]) || !ft_isdigit(in[i]) || in[i] != '_')
            return (false);
        else
            i++;
    }
    return (printf("TRUE 2\n"), true);
}

// var need to have =
// only alpha a-z/A-Z or _ at start for the name
// whatever in "" after the =