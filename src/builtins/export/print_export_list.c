#include "../../../include/minishell.h"

void print_export_list(t_export_list **list)
{
    t_export_list *head;

    head = *list;
    while (head)
    {
        printf("declare -x %s=\"%s\"", head->name, head->value);
        head = head->next;
    }
}