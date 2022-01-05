#include "libft.h"

void *ft_memchr(const void *str, int c, size_t n)
{
    unsigned char *s;
    unsigned char cc;

    cc = (unsigned char)c;
    s = (unsigned char *)str;
    if (! n)
        return (NULL);
    while (*s && *s != cc && --n)
        s++;
    if (*s == cc)
        return (s);
    return (NULL);
}