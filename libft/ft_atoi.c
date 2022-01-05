#include "libft.h"

static int ft_isspace(char c)
{
    if (c == 32)
        return (1);
    if (c > 8 && c < 14)
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int sign;
    long res;

    res = 0;
    sign = 1;
    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
        if (*str++ == '-')
            sign = -1;
    while (ft_isdigit(*str) && res < 2147483648)
        res = res * 10 + *str++ - 48;
    if (res > 2147483648)
    {
        if (sign == -1)
            return (0);
        return (-1);
    }
    return (sign * (int)res);
}