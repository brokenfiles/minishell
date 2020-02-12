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

void    redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) != -1)
			close(oldfd);
	}
}

void    exec_pipeline(char ***cmds, char **env, int pos, int in_fd, t_data *data)
{
	pid_t   process;
	int     fd[2];
	int     status;

	if (cmds[pos + 1] == NULL)
	{
		redirect(in_fd, STDIN_FILENO);
		process = fork();
		if (process == 0)
			exec_prog2(cmds[pos][0], cmds[pos], data);
		else
			waitpid(process, &status, 0);
	}
	else
	{
		pipe(fd);
		process = fork();
		if (process == 0)
		{
			close(fd[0]);
			redirect(in_fd, STDIN_FILENO);
			redirect(fd[1], STDOUT_FILENO);
			exec_prog2(cmds[pos][0], cmds[pos], data);
		}
		else
		{
			waitpid(process, &status, 0);
			close(fd[1]);
			close(in_fd);
			exec_pipeline(cmds, env, pos + 1, fd[0], data);
		}
	}
}

int	get_path2(char **command, t_data *data)
{
	struct stat	buff;
	char		**paths;
	char		*joined;
	char		*tmp;
	int			index;

	index = 0;
	stat(*command, &buff);
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
			stat((joined = ft_strjoin(joined, *command)), &buff);
			free(tmp);
			if (S_ISREG(buff.st_mode))
			{
//				free(command);
				*command = joined;
				break;
			}
			free(joined);
			index++;
		}
		free_splitted(paths, 0);
	}
	return (EXIT_SUCCESS);
}

int	exec_prog2(char *command, char **line, t_data *data)
{
	char		**arguments;
	char		*tmp;
	int			index;
	int			status;

	index = 0;
	status = 0;
	get_path2(&command, data);
	arguments = line;
	index = 0;
	while (arguments[index])
	{
		tmp = arguments[index];
		arguments[index] = ft_strtrim(arguments[index], "\"'");
		free(tmp);
		index++;
	}
	execve(command, arguments, data->env);
	free_splitted(arguments, 0);
	return (status);
}


int	exec_prog(t_data *data)
{
	char		**arguments;
	char		*tmp;
	pid_t		pid;
	int			index;
	int			status;

	index = 0;
	status = 0;
	get_path(data);
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
		waitpid(pid, &status, 0);
	if (status == 11 || status == 10)
		status += 128;
	if (status != 139 && status != 138)
		status = status ? EXIT_FAILURE : EXIT_SUCCESS;
	free_splitted(arguments, 0);
	return (status);
}
