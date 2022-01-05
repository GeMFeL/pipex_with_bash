#include "pipex.h"

static char *ft_get_cmd_full_path(char *paths[], char const *cmd)
{
	char 	*path_slash;
    char 	*cmd_full_path;
    int   	i;

    i = 0;
	if (! cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));

    while (paths[i])
    {
		path_slash = ft_strjoin(paths[i], "/");
        cmd_full_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
        if (access(cmd_full_path, F_OK) == 0)
            return (cmd_full_path);
        free(cmd_full_path);
        i++;
    }
    ft_put_custom_error_exit("pipex: command not found: ", cmd, 0);
	return (NULL);
}

static void	ft_exec_cmd(char const *cmd, char *args[], int infd, int outfd)
{
	char 	*envp[1];

	envp[0] = NULL;
	if (dup2(infd, 0) < 0 || dup2(outfd, 1) < 0)
		ft_put_perror_exit("dup2()", 5);

	if (cmd)
	{
		if (execve(cmd, args, envp) < 0)
			ft_put_perror_exit(cmd, 5);
	}
	else
		exit(5);
}

static int ft_fork_child_proc(char const *cmd, char *paths[], int infd)
{
	char 	**cmd_and_args;
	char 	*cmd_full_path;
	pid_t 	pid;
	int 	fd_pipe[2];

	if (pipe(fd_pipe) < 0)
	{
		ft_free_2_2D_1D_pointers(paths, NULL, NULL);
		ft_put_perror_exit("pipe()", 5);
	}
	cmd_and_args = ft_split(cmd, ' ');
	if (! cmd_and_args)
		ft_put_perror_exit("malloc()", 9);
	if (! cmd_and_args[0])
		ft_put_custom_error_exit(cmd, ": invalid command", 0);

	cmd_full_path = ft_get_cmd_full_path(paths, cmd_and_args[0]);
	pid = fork();
	if (pid < 0)
	{
		ft_free_2_2D_1D_pointers(paths, cmd_and_args, cmd_full_path);
		ft_put_perror_exit("fork()", 5);
	}
	if (! pid)
		ft_exec_cmd(cmd_full_path, cmd_and_args, infd, fd_pipe[1]);
	else
	{
		wait(NULL);
		close(fd_pipe[1]);
		close(infd);
		ft_free_2_2D_1D_pointers(NULL, cmd_and_args, cmd_full_path);
	}
	return (fd_pipe[0]);
}

void ft_pipex(int args_count, char const *args[], char *paths[])
{
	int		fd_outfile;
	int		fd_read;
	int 	index;

	index = 0;
	fd_read = open(args[index], O_RDONLY);
	if (fd_read < 0)
	{
		ft_free_2_2D_1D_pointers(paths, NULL, NULL);
		ft_put_perror_exit(args[index], 5);
	}

	while (++index < args_count - 1)
		fd_read = ft_fork_child_proc(args[index], paths, fd_read);

	fd_outfile = open(args[index], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
	{
		ft_free_2_2D_1D_pointers(paths, NULL, NULL);
		ft_put_perror_exit(args[index], 1);
	}

	if (ft_read_from_write_to(fd_read, fd_outfile) < 0)
	{
		ft_free_2_2D_1D_pointers(paths, NULL, NULL);
        ft_put_perror_exit("read()", 1);
	}
}
