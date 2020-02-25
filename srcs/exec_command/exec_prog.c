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
		if (!(joined = get_env_str(data, "PATH")))
			return (0);
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
//	if (ft_strncmp(cmds[0], "./", 2) != 0)
	get_path(data, cmds);
	if (execve(cmds[0], cmds, data->env) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmds[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (0);
	}
	return (1);
}
