/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:03 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/05 14:03:51 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_2d_pointer(char *ptr_2D[])
{
	int	i;

	i = 0;
	if (ptr_2D)
	{
		while (ptr_2D[i])
			free(ptr_2D[i++]);
		free(ptr_2D);
	}
}

void	ft_free_perror_exit(char **ptr2D, char const *error_str)
{
	ft_free_2d_pointer(ptr2D);
	perror(error_str);
	exit (EXIT_FAILURE);
}

void	ft_put_custom_error(char const *str_error1, char const *str_error2)
{
	if (str_error1)
		ft_putstr_fd(str_error1, 2);
	if (str_error2)
		ft_putstr_fd(str_error2, 2);
	if (str_error1 || str_error2)
		write(2, "\n", 1);
}

void	ft_perror_then_exit(char const *str_error)
{
	perror(str_error);
	exit(EXIT_FAILURE);
}
