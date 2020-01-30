
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

int	exec_command(t_data *data)
{
	if (ft_strcmp(data->command, "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(data->command, "env") == 0)
		data->last_return = get_env(data);
	else if (ft_strcmp(data->command, "pwd") == 0)
		data->last_return = get_pwd(data);
	else if (ft_strcmp(data->command, "cd") == 0)
		data->last_return = get_cd(data);
	else if (ft_strcmp(data->command, "echo") == 0)
		data->last_return = get_echo(data);
	else if ((data->last_return = exec_prog(data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
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
		if (get_command(data) == 0)
			return (fsp(commands, data->command, 0, COMMAND_NOT_FOUND));
		if (!get_arguments(data))
			return (fsp(commands, data->command, 0, ARGUMENTS_ERROR));
		exec_command(data);
		free(data->command);
		free_splitted(data->arguments, 0);
		index++;
	}
	free_splitted(commands, 0);
	return (1);
}