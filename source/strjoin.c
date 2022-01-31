#include "source.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *r;
    char *save_r;

    if (! s1 || ! s2)
        return (NULL);
    r = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (! r)
        return (r);
    save_r = r;
    while (*s1)
        *r++ = *s1++;
    while (*s2)
        *r++ = *s2++;
    *r = 0;
    return (save_r);
}