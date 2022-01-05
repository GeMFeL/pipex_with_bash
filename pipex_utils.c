#include "pipex.h"

void ft_free_2_2D_1D_pointers(char *ptr_2D_1[], char *ptr_2D_2[], char *ptr)
{
    int i;

    i = 0;
    if (ptr_2D_1)
    {
        while (ptr_2D_1[i])
            free(ptr_2D_1[i++]);
        free(ptr_2D_1);
    }

    i = 0;
    if (ptr_2D_2)
    {
        while (ptr_2D_2[i])
            free(ptr_2D_2[i++]);
        free(ptr_2D_2);
    }
    if (ptr)
        free(ptr);
}

void ft_put_perror_exit(char const *str, int ext)
{
    if (str)
        perror(str);
    if (ext)
        exit(ext);
}

void ft_put_custom_error_exit(char const *s1, char const *s2, int ext)
{
    if (s1)
    	ft_putstr_fd((char *)s1, 2);
    if (s2)
	    ft_putstr_fd((char *)s2, 2);
    if (s1 || s2)
    {
        write(2, "\n", 1);
    }
    if (ext)
    	exit(ext);
}

int ft_read_from_write_to(int infd, int outfd)
{
    char    buff[101];
    int     read_size;

    while (1)
    {
        read_size = read(infd, buff, 100);
        if (read_size < 0)
            return (-1);

        if (! read_size)
            return 0;

        buff[read_size] = '\0';
        ft_putstr_fd(buff, outfd);
    }
    return (0);
}
