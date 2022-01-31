#include "pipex.h"

static char *ft_get_cmd_full_path(char *paths[], char const *cmd)
{
	char 	*path_slash;
    char 	*cmd_full_path;

	if (! cmd)
	{
		ft_put_custom_error(COMMAND_NOT_FOUND_ERROR, "");
		return (NULL);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
    while (paths && *paths)
    {
		path_slash = ft_strjoin(*paths, "/");
        cmd_full_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (! cmd_full_path)
			ft_free_perror_exit(paths, NULL, NULL, MALLOC_ERROR);
        if (access(cmd_full_path, F_OK) == 0)
            return (cmd_full_path);
        free(cmd_full_path);
        paths++;
    }
    ft_put_custom_error(COMMAND_NOT_FOUND_ERROR, cmd);
	return (NULL);
}

static void	ft_exec_cmd(char const *cmd_path, char *args[], int infd, int outfd)
{
	char 	*envp[1];

	envp[0] = NULL;
	// (void)infd;
	// (void)outfd;
	if (dup2(infd, 0) < 0 || dup2(outfd, 1) < 0)
	{
		perror(DUP2_ERROR);
		exit (EXIT_FAILURE);
	}
	if (cmd_path)
	{
		if (execve(cmd_path, args, envp) < 0)
		{
			perror(args[0]);
			exit (EXIT_FAILURE);
		}
	}
	else
		exit(0);
}

int ft_fork_child_proc_to_exec_cmd(char const *cmd, char *paths[], int infd)
{
	char 	**cmd_and_args;
	char	*cmd_full_path;
	pid_t 	pid;
	int 	fd_pipe[2];

	if (pipe(fd_pipe) < 0)
		ft_free_perror_exit(paths, NULL, NULL, PIPE_ERROR);
	cmd_and_args = ft_split(cmd, ' ');
	if (! cmd_and_args)
		ft_free_perror_exit(paths, NULL, NULL, MALLOC_ERROR);
	cmd_full_path = ft_get_cmd_full_path(paths, cmd_and_args[0]);
	pid = fork();
	if (pid < 0)
		ft_free_perror_exit(paths, cmd_and_args, cmd_full_path, FORK_ERROR);
	if (! pid)
		ft_exec_cmd(cmd_full_path, cmd_and_args, infd, fd_pipe[1]);
	else
	{
		if (waitpid(pid, NULL, WNOHANG) < 0)
			ft_free_perror_exit(paths, cmd_and_args, cmd_full_path, WAITPID_ERROR);
		close(fd_pipe[1]);
		close(infd);
		ft_free_2D_pointer(cmd_and_args);
		free(cmd_full_path);
	}
	return (fd_pipe[0]);
}
