/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:23 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/05 14:03:14 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_read_from_write_to(int infd, int outfd)
{
	char	buff[11];
	int		read_size;

	while (1)
	{
		read_size = read(infd, buff, 10);
		if (read_size < 0)
			return (-1);
		if (! read_size)
			return (0);
		buff[read_size] = '\0';
		ft_putstr_fd(buff, outfd);
	}
	return (0);
}

void	ft_pipex_multiple_pipes(int args_count, char **args, char **envp)
{
	int	fd_outfile;
	int	fd_read;
	int	index;

	index = 0;
	fd_read = open(args[index], O_RDONLY);
	if (fd_read < 0)
		ft_perror_then_exit(args[index]);
	while (++index < args_count - 1)
		fd_read = ft_fork_child_proc_to_exec_cmd(envp, args[index], fd_read);
	fd_outfile = open(args[index], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_outfile < 0)
		ft_perror_then_exit(args[index]);
	if (ft_read_from_write_to(fd_read, fd_outfile) < 0)
		ft_perror_then_exit(READ_ERROR);
}

void	ft_pipex_here_doc(int args_count, char **args, char **envp)
{
	int	fd_outfile;
	int	fd_read;
	int	index;

	index = 0;
	fd_read = ft_get_here_doc(args[index]);
	if (fd_read < 0)
		ft_perror_then_exit("heredoc");
	while (++index < args_count - 1)
		fd_read = ft_fork_child_proc_to_exec_cmd(envp, args[index], fd_read);
	fd_outfile = open(args[index], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd_outfile < 0)
		ft_perror_then_exit(args[index]);
	if (ft_read_from_write_to(fd_read, fd_outfile) < 0)
		ft_perror_then_exit(READ_ERROR);
}
