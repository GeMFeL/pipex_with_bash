#include "source.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *ss1;
    unsigned char *ss2;

    ss1 = (unsigned char *)s1;
    ss2 = (unsigned char *)s2;
    if (! n)
        return (0);
    while (*ss1 && *ss2 && *ss1 == *ss2 && --n)
		{
			ss1++;
			ss2++;
		}
    return (*ss1 - *ss2);
}