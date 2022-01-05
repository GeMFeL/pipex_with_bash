#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
    char *s;
    int len;

    s = (char *)str;
    len = ft_strlen(str);
    if (! c)
        return (s + len);
    while (len--)
        if (s[len] == c)
            return (s + len);
    return (NULL);
}
