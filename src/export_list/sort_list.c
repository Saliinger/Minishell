#include "../../include/minishell.h"
#include <stdlib.h>
#include <string.h>

// Function to find the middle of the list
t_export_list *find_middle(t_export_list *head) {
    t_export_list *slow = head;
    t_export_list *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted lists
t_export_list *merge_sorted_lists(t_export_list *left, t_export_list *right) {
    if (!left)
        return right;
    if (!right)
        return left;

    t_export_list *result = NULL;

    // Compare names and merge
    if (strcmp(left->name, right->name) <= 0) {
        result = left;
        result->next = merge_sorted_lists(left->next, right);
    } else {
        result = right;
        result->next = merge_sorted_lists(left, right->next);
    }

    return result;
}

void merge_sort(t_export_list **head_ref) {
    if (!head_ref || !*head_ref || !(*head_ref)->next)
        return; // Base case: empty list or single node

    t_export_list *head = *head_ref;
    t_export_list *middle = find_middle(head);
    t_export_list *right_half = middle->next;

    middle->next = NULL; // Split the list into two halves

    // Recursively sort each half
    merge_sort(&head);
    merge_sort(&right_half);

    // Merge the sorted halves
    *head_ref = merge_sorted_lists(head, right_half);
}
