#include "../../includes/minishell.h"

int	get_path(t_data *data, char **cmds)
{
	struct stat	buff;
	char		**paths;
	char		*joined;
	char		*tmp;
<<<<<<< HEAD
=======
	int			ret;
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	int			index;

	index = 0;
	data->command = cmds[0];
<<<<<<< HEAD
	stat(data->command, &buff);
	if (!S_ISREG(buff.st_mode))
=======
	ret = stat(data->command, &buff);
	if (ret == -1 || !S_ISREG(buff.st_mode) || ft_strncmp(data->command, "./", 2))
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
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
<<<<<<< HEAD
=======
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
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	return (EXIT_SUCCESS);
}

int	exec_prog(t_data *data, char **cmds)
{
	char		*tmp;
	int			index;

	index = 0;
	get_path(data, cmds);
	index = 0;
	while (cmds[index])
	{
		tmp = cmds[index];
		cmds[index] = ft_strtrim(cmds[index], "\"'");
		free(tmp);
		index++;
	}
	if (execve(cmds[0], cmds, data->env) == -1)
	{
		ft_printf("minishell: command not found: %s\n", cmds[0]);
		return (0);
	}
	return (1);
	/*if (status == 11 || status == 10)
		status += 128;
	if (status != 139 && status != 138)
		status = status ? EXIT_FAILURE : EXIT_SUCCESS;*/
}
