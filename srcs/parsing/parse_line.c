
#include "../../includes/minishell.h"

int	command_exists(t_data *data)
{
	struct stat	buf;
	char		**paths;
	char		*joined;
	char		*tmp;
	int			index;
	char		*command;

	command = data->command;
	if ((ft_strcmp(command, "echo") == 0) || (ft_strcmp(command, "cd") == 0)
		|| (ft_strcmp(command, "pwd") == 0) || (ft_strcmp(command, "export") == 0)
		|| (ft_strcmp(command, "unset") == 0) || (ft_strcmp(command, "env") == 0)
		|| (ft_strcmp(command, "exit") == 0))
		return (1);
	index = 0;
	stat(command, &buf);
	if ((S_ISREG(buf.st_mode) && (ft_strchr(command, '/'))))
		return (1);
	if (!(joined = get_env_str(data, "PATH")))
		return (0);
	paths = ft_split(joined, ':');
	free(joined);
	while (paths[index])
	{
		joined = ft_strjoin(paths[index], "/");
		tmp = joined;
		stat((joined = ft_strjoin(joined, command)), &buf);
		free(tmp);
		free(joined);
		if ((S_ISREG(buf.st_mode)))
			return (free_splitted(paths, 1));
		index++;
	}
	free_splitted(paths, 1);
	return (0);
}

int	get_command(t_data *data)
{
	int		start;
	int		len;

	start = 0;
	while (data->line[start] == ' ')
		start++;
	len = 0;
	while (data->line[len + start] && data->line[len + start] != ' ')
		len++;
	data->command = ft_substr(data->line, start, len);
	return (command_exists(data));
}

int	get_arguments(t_data *data)
{
	char	*arguments;
	int		index;

	index = 0;
	while (data->line[index] == ' ')
		index++;
	index += ft_strlen(data->command);
	arguments = data->line + index;
	while (data->line[index++] == ' ')
		arguments++;
	data->arguments_line = arguments;
	return (parse_arguments(data));
}

int	run_command(t_data *data, int (f)(t_data *data))
{
	if (ft_strcmp(data->command, "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(data->command, "env") == 0)
		data->last_return = exec_env(data);
	else if (ft_strcmp(data->command, "pwd") == 0)
		data->last_return = exec_pwd(data);
	else if (ft_strcmp(data->command, "cd") == 0)
		data->last_return = exec_cd(data);
	else if (ft_strcmp(data->command, "echo") == 0)
		data->last_return = exec_echo(data);
	else if (ft_strcmp(data->command, "unset") == 0)
		data->last_return = exec_unset(data);
	else if (ft_strcmp(data->command, "export") == 0)
		data->last_return = exec_export(data);
	else if ((data->last_return = f(data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	has_redirect(t_data *data, int way)
{
	int	index;

	index = 0;
	while (data->redirects[index].type != -1)
	{
		if (data->redirects[index].way == way)
			return (1);
		index++;
	}
	return (0);
}

int	has_pipe(t_data *data)
{
	int	index;

	index = 0;
	while (data->redirects[index].type != -1)
	{
		if (data->redirects[index].type == PIPE)
			return (1);
		index++;
	}
	return (0);
}

int		stop_redirect(int fd, int dup, int std)
{
	if ((dup2(dup, std)) < 1)
		return (-1);
	close(fd);
	return (EXIT_SUCCESS);
}

int		redirect_output(t_redirect redirect)
{
	int	fd;

	if (!(fd = open(redirect.file, redirect.type == DOUBLE_AQUOTE ? O_RDWR | O_CREAT | O_APPEND
	: O_RDWR | O_CREAT | O_TRUNC, 0644)))
		return (-1);
	if (dup2(fd, STDOUT_FILENO) < 1)
		return (-1);
	return (fd);
}

int		redirect_input(t_redirect redirect)
{
	struct stat	buff;
	int			fd;
	int			ret;

	ret = stat(redirect.file, &buff);
	if (ret == -1 || S_ISDIR(buff.st_mode))
		return (EXIT_FAILURE);
	if (!(fd = open(redirect.file, O_RDONLY)))
		return (-1);
	if (dup2(fd, STDIN_FILENO) < 1)
		return (-1);
	return (fd);
}

int	exec_command(t_data *data)
{
	int	index;
	int	index2;
	int	fd;
	int	fd2;
	int	stds[2];

	index = 0;
	if (has_pipe(data))
	{
		char **split = ft_split(data->line, '|');
		int i = 0, ac = tabsize(split);
		char	***commands;
		while (split[i])
		{
			int		y;

			y = -1;
			if (!(commands = (char***)malloc(sizeof(char**) * ac)))
				return (0);
			commands[ac] = NULL;
			while (++y < ac)
			{
				ft_putstr_fd(split[i], 2);
				commands[y] = ft_split(split[i], ' ');
				ft_putstr_fd("yo\n", 2);
			}
			i++;
		}
		exec_pipeline(commands, data->env, 0, STDIN_FILENO);
	}
	while (data->redirects[index].type != -1)
	{
		if (data->redirects[index].way == RIGHT)
		{
			stds[1] = dup(1);
			fd = redirect_output(data->redirects[index]);
			if (has_redirect(data, LEFT))
			{
				index2 = 0;
				while (data->redirects[index2].type != -1)
				{
					if (data->redirects[index2].way == LEFT)
					{
						stds[0] = dup(0);
						fd2 = redirect_input(data->redirects[index2]);
						run_command(data, exec_prog);
						stop_redirect(fd2, stds[0], STDIN_FILENO);
					}
					index2++;
				}
			}
			else
				run_command(data, exec_prog);
			stop_redirect(fd, stds[1], STDOUT_FILENO);
		}
		else if (data->redirects[index].way == LEFT && !has_redirect(data, RIGHT))
		{
			stds[0] = dup(0);
			fd = redirect_input(data->redirects[index]);
			run_command(data, exec_prog);
			stop_redirect(fd, stds[0], STDIN_FILENO);
			close(stds[0]);
		}
		index++;
	}
	if (data->redirects[0].type == -1)
		run_command(data, exec_prog);
	reset_redirections(data, 1);
	return (EXIT_SUCCESS);
}

int	parse_line(t_data *data)
{
	char	**commands;
	int		index;

	index = 0;
	commands = ft_split(data->line, ';');
	while (commands[index])
	{
		if (data->line)
			free(data->line);
		data->line = ft_strdup(commands[index]);
		get_redirections(data);
		if (get_command(data) == 0)
		{
			data->last_return = ERR_COMMAND_NOT_FOUND;
			return (fsp(commands, data->command, 0, COMMAND_NOT_FOUND));
		}
		if (get_arguments(data) == 0)
		{
			data->last_return = EXIT_FAILURE;
			return (fsp(commands, data->command, 0, ARGUMENTS_ERROR));
		}
		if (exec_command(data) == EXIT_FAILURE)
		{
			data->last_return = EXIT_FAILURE;
			return (fsp(commands, data->command, 0, INVALID_FILE));
		}
		free(data->command);
		free_splitted(data->arguments, 0);
		index++;
	}
	free_splitted(commands, 0);
	return (1);
}