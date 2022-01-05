#ifndef PIPEX_H
#define PIPEX_H

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

void ft_free_2_2D_1D_pointers(char *ptr_2D_1[], char *ptr_2D_2[], char *ptr);
void ft_put_perror_exit(char const *str, int ext);
void ft_put_custom_error_exit(char const *s1, char const *s2, int ext);
int ft_read_from_write_to(int infd, int outfd);
void ft_pipex(int args_count, char const *args[], char *paths[]);

#endif
