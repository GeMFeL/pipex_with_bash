#include "source.h"

char *ft_strchr(const char *str, int c)
{
    if (! str)
        return (NULL);
    while (*str && *str != c)
        str++;
    if (*str == c)
        return ((char *)str);
    return (NULL);
}