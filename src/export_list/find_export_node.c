//
// Created by anoukan on 12/6/24.
//

#include "../../include/minishell.h"

int ft_strcmp2(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}


t_export_list *find_export_node(char *name, t_export_list **lst)
{
    t_export_list *to_find;

    to_find = *lst;
    while (to_find)
    {
        printf("Comparing '%s' with '%s'\n", name, to_find->name);
        if (ft_strcmp2(name, to_find->name) == 0)
            return (to_find);
        to_find = to_find->next;
    }
    return (NULL);
}