#include "libft.h"

static int ft_ismatch(char *s, char *q)
{
    while (*s && *q && *s == *q)
    {
        s++;
        q++;
    }
    if (! *q)
        return (1);
    return (0);
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    char *s;
    char *q;
    size_t qlen;

    if (! *needle)
        return ((char *)haystack);
    s = (char *)haystack;
    q = (char *)needle;
    qlen = ft_strlen(needle);
    while (*s && qlen <= len--)
    {
        if (*s == *q && ft_ismatch(s, q))
			return (s);
        s++;
    }
    return (NULL);
}
