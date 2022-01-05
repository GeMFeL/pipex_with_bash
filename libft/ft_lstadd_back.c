#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *list;

    if (! *lst)
    {
        *lst = new;
        return;
    }
    list = *lst;
    while (list->next)
        list = list->next;
    list->next = new;
}