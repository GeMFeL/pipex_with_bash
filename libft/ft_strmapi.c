#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *r;
    unsigned int i;

    if (! s)
        return (NULL);
    r = malloc(ft_strlen(s) + 1);
    if (! r)
        return (r);
    i = 0;
    while (s[i])
    {
        r[i] = f(i, s[i]);
        i++;
    }
    r[i] = 0;
    return (r);
}