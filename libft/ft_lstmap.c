#include "libft.h"


t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *map;

    if (! lst)
        return (NULL);
    map  = ft_lstnew(f(lst->content));
    if (! map)
    {
        ft_lstclear(&map, del);
        return (NULL);
    }
    map->next = ft_lstmap(lst->next, f, del);
    return (map);
}
