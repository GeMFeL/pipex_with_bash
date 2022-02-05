/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:28 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/05 13:57:27 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_pipex(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("invalid arguments\n", 2);
		exit (EXIT_FAILURE);
	}
	if (argc == 6 && ! ft_strncmp(argv[1], "here_doc", 9))
		ft_pipex_here_doc(argc - 2, argv + 2, envp);
	else
		ft_pipex_multiple_pipes(argc - 1, argv + 1, envp);
}

int	main(int argc, char **argv, char **envp)
{
	ft_pipex(argc, argv, envp);
	return (0);
}
