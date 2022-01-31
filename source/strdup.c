#include "source.h"

char *ft_strdup(const char *string)
{
    char *r;
    char *save_r;
    size_t l;

    l = ft_strlen(string);
    r = (char *)malloc(l + 1);
    if (! r)
        return (NULL);
    save_r = r;
    while (*string)
        *r++ = *string++;
    *r = 0;
    return (save_r);
}