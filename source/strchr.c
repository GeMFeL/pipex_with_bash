/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:24:32 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/01 11:24:33 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

char *ft_strchr(const char *str, int c)
{
    if (! str)
        return (NULL);
    while (*str && *str != c)
        str++;
    if (*str == c)
        return ((char *)str);
    return (NULL);
}