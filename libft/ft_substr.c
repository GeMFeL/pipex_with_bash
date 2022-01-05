#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *r;
    char *save_r;

    if (! s)
        return (0);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));

    r = malloc((len + 1) * sizeof(char)); 
    if (! r)
        return (NULL);
    save_r = r;
    while (len--)
        *r++ = s[start++];

    *r = 0;
    return (save_r);
}
