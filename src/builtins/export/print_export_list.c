#include "../../../include/minishell.h"

void print_export_list(t_export_list **list)
{
    t_export_list *current = *list;
    while (current)
    {
        if (current->value)
            printf("declare -x %s=\"%s\"\n", current->name, current->value);
        else
            printf("declare -x %s\n", current->name);
        current = current->next;
    }
}