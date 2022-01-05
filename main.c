#include "pipex.h"

static char *ft_get_trimed_PATH_from_envp(char *envp[])
{
	int 	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5); // +5 is for trim 'PATH=' string from beguining.
		i++;
	}
	return (NULL);
}

static char **ft_get_splited_PATH_env(char *envp[])
{
	char 	*path_env;
	char	**paths;

	path_env = ft_get_trimed_PATH_from_envp(envp);
	paths = ft_split(path_env, ':');
	if (! paths)
		ft_put_perror_exit("malloc()", 5);
	return (paths);
}

int main(int argc, char const *argv[], char *envp[])
{
	char **paths;

	if (argc < 5)
		return (1);
	paths = ft_get_splited_PATH_env(envp);
	ft_pipex(argc - 1, argv + 1, paths);
	ft_free_2_2D_1D_pointers(paths, NULL, NULL);
	return (0);
}
