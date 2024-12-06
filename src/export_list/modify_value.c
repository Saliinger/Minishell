//
// Created by anoukan on 12/6/24.
//

#include "../../include/minishell.h"

int modify_value(t_export_list **lst, char *name, char *value)
{
    t_export_list *tmp;

    tmp = find_export_node(name, lst);
    if (tmp)
    {
        if (tmp->value)
            free(tmp->value);
        tmp->value = value;
    }
    else
        return (1);
    return (0);
}