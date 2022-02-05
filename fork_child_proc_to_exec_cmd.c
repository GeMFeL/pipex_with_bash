/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child_proc_to_exec_cmd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:06 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/05 14:09:08 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_cmd(char **envp, char **bash_and_cmd, int infd, int outfd)
{
	char	*bash_path;

	bash_path = "/bin/bash";
	if (dup2(infd, 0) < 0 || dup2(outfd, 1) < 0)
	{
		perror(DUP2_ERROR);
		exit (EXIT_FAILURE);
	}
	if (execve(bash_path, bash_and_cmd, envp) < 0)
	{
		perror(bash_path);
		exit (EXIT_FAILURE);
	}
}

int	ft_fork_child_proc_to_exec_cmd(char **envp, char *cmd, int infd)
{
	pid_t	pid;
	int		fd_pipe[2];
	char	**bash_args_and_cmd;

	if (pipe(fd_pipe) < 0)
		ft_perror_then_exit(PIPE_ERROR);
	bash_args_and_cmd = malloc(4 * sizeof(char *));
	if (! bash_args_and_cmd)
		ft_perror_then_exit(MALLOC_ERROR);
	bash_args_and_cmd[0] = ft_strdup("pipex");
	bash_args_and_cmd[1] = ft_strdup("-c");
	bash_args_and_cmd[2] = ft_strdup(cmd);
	bash_args_and_cmd[3] = NULL;
	pid = fork();
	if (pid < 0)
		ft_free_perror_exit(bash_args_and_cmd, FORK_ERROR);
	if (! pid)
		ft_exec_cmd(envp, bash_args_and_cmd, infd, fd_pipe[1]);
	waitpid(pid, NULL, 0);
	close(fd_pipe[1]);
	close(infd);
	ft_free_2d_pointer(bash_args_and_cmd);
	return (fd_pipe[0]);
}
