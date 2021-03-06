/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:23:57 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/02 17:18:19 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (! s)
		return ;
	while (*s)
		write(fd, s++, 1);
}
