#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t lsrc;
    size_t ldst;
    size_t i;

    lsrc = ft_strlen(src);
    if (! dstsize)
        return (lsrc);
    ldst = ft_strlen(dst);
    i = ldst;
    while (*src && i < dstsize - 1)
        dst[i++] = *src++;
    dst[i] = 0;
    if (dstsize < ldst)
        return (lsrc + dstsize);
    return (lsrc + ldst);
}