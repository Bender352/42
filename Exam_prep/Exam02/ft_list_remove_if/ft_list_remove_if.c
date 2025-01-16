#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;  

    if (*begin_list == NULL || begin_list == NULL || data_ref == NULL)
        return;
    current = *begin_list;
    if (0 == cmp (current->data, data_ref))
    {
        *begin_list = current->next;
        free (current);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
        ft_list_remove_if(&current->next, data_ref, cmp);
}