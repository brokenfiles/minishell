
#include "../../includes/minishell.h"

int command_exists(t_data *data)
{
	struct stat buf;
	char **paths;
	char *joined;
	char *tmp;
	int index;
	char *command;

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

int run_command(t_data *data, char **cmds)
{
	if (ft_strcmp(cmds[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(cmds[0], "env") == 0)
		data->last_return = exec_env(data, cmds);
	else if (ft_strcmp(cmds[0], "pwd") == 0)
		data->last_return = exec_pwd(data, cmds);
	else if (ft_strcmp(cmds[0], "cd") == 0)
		data->last_return = exec_cd(data, cmds);
	else if (ft_strcmp(cmds[0], "echo") == 0)
		data->last_return = exec_echo(data, cmds);
	else if (ft_strcmp(cmds[0], "unset") == 0)
		data->last_return = exec_unset(data, cmds);
	else if (ft_strcmp(cmds[0], "export") == 0)
		data->last_return = exec_export(data, cmds);
	else if ((data->last_return = exec_prog(data, cmds)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int parse_line(t_data *data)
{
	char **commands;
	int index;

	index = 0;
	commands = ft_split(data->line, ';');
	while (commands[index])
	{
		if (data->line)
			free(data->line);
		data->line = ft_strdup(commands[index]);
		if (exec_hub(data) == EXIT_FAILURE)
		{
			data->last_return = EXIT_FAILURE;
//			return (fsp(commands, data->command, 0, INVALID_FILE));
			return (free_splitted(commands, EXIT_FAILURE));
		}
//		reset_redirections(data);
		index++;
	}
	free_splitted(commands, 0);
	return (EXIT_SUCCESS);
}