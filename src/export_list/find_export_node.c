//
// Created by anoukan on 12/6/24.
//

#include "../../include/minishell.h"

t_export_list *find_export_node(char *name, t_export_list **lst)
{
    t_export_list *to_find;

    to_find = *lst;
    while (to_find && ft_strcmp(name, to_find->name) != 0)
        to_find = to_find->next;
    if (to_find && ft_strcmp(name, to_find->name) == 0)
        return (to_find);
    return (NULL);
}