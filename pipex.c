#include "pipex.h"

static char *ft_get_trimed_PATH_from_envp(char const *envp[])
{
	int 	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return ((char *)envp[i] + 5); // +5 is for trim 'PATH=' string from beguining.
		i++;
	}
	return (NULL);
}

static char **ft_get_splited_PATH_env(char const *envp[])
{
	char 	*path_env;
	char	**paths;

	path_env = ft_get_trimed_PATH_from_envp(envp);
	paths = ft_split(path_env, ':');
	if (! paths)
	{
		perror(MALLOC_ERROR);
		exit(EXIT_FAILURE);
	}
	return (paths);
}

void ft_pipex(int argc, char const **argv, char const **envp)
{
	char	**paths;

	if (argc < 5)
		exit (EXIT_FAILURE);
	paths = ft_get_splited_PATH_env(envp);

	if (argc == 6 && ! ft_strncmp(argv[1], "here_doc", 9))
		ft_pipex_here_doc(argc - 2, argv + 2, paths);
	else
		ft_pipex_multiple_pipes(argc - 1, argv + 1, paths);

	ft_free_2D_pointer(paths);
    waitpid(-1, NULL, 0);
}
