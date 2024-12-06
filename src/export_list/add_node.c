//
// Created by anoukan on 06/12/24.
//

#include "../../include/minishell.h"

int add_node_export(t_export_list **list, char *name, char *value)
{
    t_export_list *new;
    t_export_list *tmp;

    new = (t_export_list *) malloc(sizeof(t_export_list));
    if (!new)
        return (free(name), free(value), 1);
    new->name = name;
    new->value = value;
    new->next = NULL;
    if (list && new)
    {
        if (!*list)
            *list = new;
        else
        {
            tmp = *list;
            while(tmp->next)
                tmp = tmp->next;
            tmp->next = new;
        }
    }
    return (0);
}