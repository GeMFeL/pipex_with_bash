/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:28 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/05 13:34:57 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("invalid arguments\n", 2);
		exit (EXIT_FAILURE);
	}
	ft_pipex_multiple_pipes(argc - 1, argv + 1, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	ft_pipex(argc, argv, envp);
	return (0);
}
