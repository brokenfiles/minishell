#include "../../includes/minishell.h"

int	exec_prog(t_data *data)
{
	struct stat	buff;
	char		**arguments;
	char		**paths;
	char		*joined;
	char		*tmp;
	pid_t		pid;
	int			index;

	index = 0;
	stat(data->command, &buff);
	if (!S_ISREG(buff.st_mode))
	{
		if (!(joined = get_env_str(data, "PATH")))
			return (0);
		paths = ft_split(joined, ':');
		free(joined);
		while (paths[index])
		{
			joined = ft_strjoin(paths[index], "/");
			tmp = joined;
			stat((joined = ft_strjoin(joined, data->command)), &buff);
			free(tmp);
			if (S_ISREG(buff.st_mode))
			{
				free(data->command);
				data->command = joined;
				break;
			}
			free(joined);
			index++;
		}
		free_splitted(paths, 0);
	}
	arguments = ft_split_spec(data->line, ' ');
	index = 0;
	while (arguments[index])
	{
		tmp = arguments[index];
		arguments[index] = ft_strtrim(arguments[index], "\"'");
		free(tmp);
		index++;
	}
	pid = fork();
	if (pid == 0)
		execve(data->command, arguments, data->env) == -1 \
			? quit("permission denied", free_splitted(arguments, EXIT_FAILURE)) : 0;
	else if (pid < 0)
		quit("failed to fork", free_splitted(arguments, EXIT_FAILURE));
	else
		wait(&pid);
	free_splitted(arguments, 0);
	return (EXIT_SUCCESS);
}
