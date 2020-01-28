
#include "../../includes/minishell.h"

int	command_exists(char *command)
{
	int	fd;

	if ((fd = open(command, O_RDONLY)) != -1 && (ft_strchr(command, '/')))
	{
		close(fd);
		return (1);
	}
	if ((ft_strcmp(command, "echo") == 0) || (ft_strcmp(command, "cd") == 0)
	|| (ft_strcmp(command, "pwd") == 0) || (ft_strcmp(command, "export") == 0)
	|| (ft_strcmp(command, "unset") == 0) || (ft_strcmp(command, "env") == 0)
	|| (ft_strcmp(command, "exit") == 0) || (ft_strncmp(command, "./", 2) == 0))
		return (1);
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
	return (command_exists(data->command));
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
	data->arguments = arguments;
	return (1);
}

int	exec_command(t_data *data)
{
	if (ft_strcmp(data->command, "exit") == 0)
		exit(EXIT_SUCCESS);
	if (ft_strcmp(data->command, "env") == 0)
		data->last_return = get_env(data);
	if (ft_strcmp(data->command, "pwd") == 0)
		data->last_return = get_pwd(data);
	if (ft_strcmp(data->command, "cd") == 0)
		data->last_return = get_cd(data);
	if (ft_strcmp(data->command, "echo") == 0)
		data->last_return = get_echo(data);
	if ((data->last_return = exec_prog(data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_line(t_data *data)
{
	char	**commands;

	commands = ft_split(data->line, ';');
	while (*commands)
	{
		data->line = *commands;
		if (get_command(data) == 0)
		{
			ft_putstr(COMMAND_NOT_FOUND);
			// free splitted
			return (0);
		}
		get_arguments(data);
		exec_command(data);
		commands++;
	}
	// free splitted
	return (1);
}