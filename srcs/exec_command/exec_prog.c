#include "../../includes/minishell.h"

int	get_path(t_data *data)
{
	struct stat	buff;
	char		**paths;
	char		*joined;
	char		*tmp;
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
	return (EXIT_SUCCESS);
}

int	exec_prog(t_data *data, char **cmds)
{
	char		*tmp;
	pid_t		pid;
	int			index;
	int			status;

	index = 0;
	status = 0;
	get_path(data);
	index = 0;
	while (cmds[index])
	{
		tmp = cmds[index];
		cmds[index] = ft_strtrim(cmds[index], "\"'");
		free(tmp);
		index++;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(data->command, cmds, data->env) == -1)
			quit("permission denied", free_splitted(cmds, EXIT_FAILURE));
	}
	else if (pid < 0)
		quit("failed to fork", free_splitted(cmds, EXIT_FAILURE));
	else
		waitpid(pid, &status, 0);
	if (status == 11 || status == 10)
		status += 128;
	if (status != 139 && status != 138)
		status = status ? EXIT_FAILURE : EXIT_SUCCESS;
	return (status);
}
