/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:28 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/02 16:14:26 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_pipex(int argc, char const **argv)
{

	if (argc < 5)
		exit (EXIT_FAILURE);

	if (argc == 6 && ! ft_strncmp(argv[1], "here_doc", 9))
		ft_pipex_here_doc(argc - 2, argv + 2);
	else
		ft_pipex_multiple_pipes(argc - 1, argv + 1);
}
