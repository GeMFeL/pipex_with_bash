#include "libft.h"

static void ft_putnbr_helper(unsigned int n, int fd)
{
    if (n < 10)
        ft_putchar_fd(n % 10 + '0', fd);
    else
    {
        ft_putnbr_helper(n / 10, fd);
        ft_putchar_fd(n % 10 + '0', fd);
    }
}

void ft_putnbr_fd(int n, int fd)
{
    unsigned int num;

    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        num = -n;
    }
    else
        num = n;
    ft_putnbr_helper(num, fd);
}