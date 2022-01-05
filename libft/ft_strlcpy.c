#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t l;

    l = ft_strlen(src);
    if (! dstsize)
        return (l);
    while (*src && --dstsize)
        *dst++ = *src++;
    *dst = 0;
    return (l);
}