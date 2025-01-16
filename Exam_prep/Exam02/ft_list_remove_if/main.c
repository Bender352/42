#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

// Comparison function for integers
int cmp_int(void *data1, void *data2)
{
    return (*(int *)data1 - *(int *)data2);
}

// Helper function to create a new node
t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print the list (for testing purposes)
void print_list(t_list *list)
{
    while (list)
    {
        printf("%d -> ", *(int *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create some nodes and a linked list
    int data1 = 10, data2 = 20, data3 = 30, data4 = 20;
    t_list *list = create_node(&data1);
    list->next = create_node(&data2);
    list->next->next = create_node(&data3);
    list->next->next->next = create_node(&data4);

    printf("Original list:\n");
    print_list(list);

    // Data to remove (value 20 in this case)
    int data_ref = 20;
    
    // Remove nodes with data equal to 20
    ft_list_remove_if(&list, &data_ref, cmp_int);

    printf("\nList after removing 20:\n");
    print_list(list);

    // Free the remaining list nodes (without freeing data)
    while (list)
    {
        t_list *temp = list;
        list = list->next;
        free(temp);  // Only free the node, not the data
    }

    return 0;
}
