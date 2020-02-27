#include "../../includes/minishell.h"

int	handle_last_command(char ***cmds, int pos, int in_fd, t_data *data)
{
	if (pos > 0)
	{
		if (is_pipeline(cmds, pos, in_fd, data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (is_command_alone(cmds, pos, in_fd, data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	while (data->end != -1)
		data->end = waitpid(data->process, &data->last_return, 0);
	handle_return(data);
	return (EXIT_SUCCESS);
}

int	exec_pipeline(char ***cmds, int pos, int in_fd, t_data *data)
{
	data->end = 0;
	data->process = -1;
	if (cmds[pos + 1] == NULL)
	{
		if (handle_last_command(cmds, pos, in_fd, data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		pipe(data->pipe);
		data->process = fork();
		if (data->process == 0)
		{
			if (exec_child(cmds, pos, in_fd, data) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
		{
			if (exec_parent(cmds, pos, in_fd, data) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	handle_commands(t_data *data, char **split, char ****commands)
{
	int	i;
	int	x;

	i = 0;
	while (i < tabsize(split))
	{
		x = 0;
		if (redirection_hub(data, &split[i], i) == EXIT_FAILURE)
		{
			free_splitted(split, 0);
			free(*commands);
			return (EXIT_FAILURE);
		}
		(*commands)[i] = ft_split_spec(split[i], ' ');
		while ((*commands)[i][x])
			remove_quotes(&(*commands)[i][x++]);
		i++;
	}
	(*commands)[i] = NULL;
	return (EXIT_SUCCESS);
}

int	exec_hub(t_data *data)
{
	int		i;
	char	***commands;
	char	**split;

	i = 0;
	if (!(split = ft_split_spec(data->line, '|')))
		return (EXIT_FAILURE);
	if (!(commands = malloc(sizeof(char **) * (tabsize(split) + 1))))
		return (free_splitted(split, EXIT_FAILURE));
	handle_commands(data, split, &commands);
	if (exec_pipeline(commands, 0, STDIN_FILENO, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < tabsize(split))
		free_splitted(commands[i++], 0);
	free(commands);
	free_splitted(split, 0);
	i = 0;
	while (i < tabsize(split))
		ft_lstclear_redirect(&data->tpipe[i++].redirect, free);
	return (EXIT_SUCCESS);
}
