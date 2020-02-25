#include "../../includes/minishell.h"

int	get_path(t_data *data, char **cmds)
{
	struct stat	buff;
	char		**paths;
	char		*joined;
	char		*tmp;
	int			ret;
	int			index;

	index = 0;
	data->command = cmds[0];
	ret = stat(data->command, &buff);
	if (ret == -1 || !S_ISREG(buff.st_mode) || ft_strncmp(data->command, "./", 2))
	{
		if (!(joined = get_env(data, "PATH")))
			return (EXIT_FAILURE);
		paths = ft_split(joined, ':');
		free(joined);
		while (paths[index])
		{
			joined = ft_strjoin(paths[index], "/");
			tmp = joined;
			ret = stat((joined = ft_strjoin(joined, data->command)), &buff);
			free(tmp);
			if (ret != -1 && S_ISREG(buff.st_mode))
			{
				free(cmds[0]);
				cmds[0] = joined;
				break;
			}
			free(joined);
			index++;
		}
		free_splitted(paths, 0);
	}
	return (EXIT_SUCCESS);
}

int	exec_prog(t_data *data, char **cmds)
{
	int			index;

	index = 0;
	if (get_path(data, cmds) == EXIT_FAILURE)
	{
		error_command_nf(cmds[0]);
		return (EXIT_FAILURE);
	}
	if (execve(cmds[0], cmds, data->env) == -1)
	{
		error_command_nf(cmds[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
