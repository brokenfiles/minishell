#include "../../includes/minishell.h"

int		is_regular_file(char *file)
{
	struct stat	buff;
<<<<<<< HEAD
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
=======

	if (stat(file, &buff) == -1)
		return (0);
	return (S_ISREG(buff.st_mode));
}

char	*get_real_path(char *dir, char *command)
{
	char	*tmp;
	char	*path;

	if (!(path = ft_strjoin(dir, "/")))
		return (NULL);
	tmp = path;
	if (!(path = ft_strjoin(path, command)))
		return (NULL);
	free(tmp);
	return (path);
}

void	free_and_replace(char **dest, char *src)
{
	free(*dest);
	*dest = src;
}

int		get_path(t_data *data, char **cmds)
{
	char	**paths;
	char	**save;
	char	*path;

	if (!is_regular_file(cmds[0]) || ft_strncmp(cmds[0], "./", 2))
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
	{
		if (!(path = get_env(data, "PATH")))
			return (EXIT_FAILURE);
		if (!(paths = ft_split(path, ':')))
			return (free_string(&path, EXIT_FAILURE));
		save = paths;
		free(path);
		while (*paths)
		{
			if (!(path = get_real_path(*(paths++), cmds[0])))
				return (free_splitted(paths - 1, EXIT_FAILURE));
			if (is_regular_file(path))
			{
				free_and_replace(&cmds[0], path);
				break ;
			}
		}
		free_splitted(save, 0);
	}
<<<<<<< HEAD
=======
	return (EXIT_SUCCESS);
}

int		exec_prog(t_data *data, char **cmds, int *ret)
{
	if (get_path(data, cmds) == EXIT_FAILURE ||
	((*ret = execve(cmds[0], cmds, data->env)) == -1))
	{
		error_command_nf(cmds[0]);
		exit(127);
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
