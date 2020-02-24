#include "../../includes/minishell.h"

int is_built_in(char *str)
{
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else
		return (0);
}

int redirect_output(t_redirect *redirect)
{
	int fd;

	if (!(fd = open(redirect->file, redirect->type == DOUBLE_AQUOTE ? O_RDWR | O_CREAT | O_APPEND
																	: O_RDWR | O_CREAT | O_TRUNC, 0644)))
		return (-1);
	if (dup2(fd, STDOUT_FILENO) < 1)
		return (-1);
	return (fd);
}

void redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			close(oldfd);
	}
}

int is_command_alone(char ***cmds, int pos, int in_fd, t_data *data)
{
	pid_t		process;

	if (is_built_in(cmds[pos][0]) == 0)
	{
		process = fork();
		if (process == 0)
		{
			if (is_right_arrow(data->tPipe[pos].redirect) == 1)
				data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
			else if (is_left_arrow(data->tPipe[pos].redirect))
				handle_left_arrow(data, data->tPipe[pos].redirect, 0);
			else
				redirect(in_fd, STDIN_FILENO);
			if (pos > 0)
				close(in_fd);
			run_command(data, cmds[pos]);
			exit(EXIT_SUCCESS);
		}

	}
	else
	{
		if (is_right_arrow(data->tPipe[pos].redirect))
		{
			data->fd[0] = dup(1);
			data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
			run_command(data, cmds[pos]);
			dup2(data->fd[0], 1);
			close(data->fd[0]);
			close(data->fd[1]);
		}
		else
			run_command(data, cmds[pos]);
	}
	return (EXIT_SUCCESS);
}

void is_pipeline(char ***cmds, int pos, int in_fd, t_data *data)
{
	pid_t process;

	process = fork();
	if (process == 0)
	{
		redirect(in_fd, STDIN_FILENO);
		if (is_right_arrow(data->tPipe[pos].redirect))
			data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
		else if (is_left_arrow(data->tPipe[pos].redirect))
			handle_left_arrow(data, data->tPipe[pos].redirect, 1);
		close(data->pipe[1]);
		run_command(data, cmds[pos]);
		exit(EXIT_SUCCESS);
	}
	close(in_fd);
}

void exec_fils(char ***cmds, int pos, int in_fd, t_data *data)
{
	close(data->pipe[0]);
	redirect(in_fd, STDIN_FILENO);
	if (is_right_arrow(data->tPipe[pos].redirect))
		data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
	else if (is_left_arrow(data->tPipe[pos].redirect))
		handle_left_arrow(data, data->tPipe[pos].redirect, 1);
	else
		redirect(data->pipe[1], 1);
	close(data->pipe[1]);
	run_command(data, cmds[pos]);
	exit(EXIT_FAILURE);
}

void exec_papa(char ***cmds, int pos, int in_fd, t_data *data)
{
	if (pos > 0)
		close(in_fd);
	close(data->pipe[1]);
	exec_pipeline(cmds, pos + 1, data->pipe[0], data);
}

int exec_pipeline(char ***cmds, int pos, int in_fd, t_data *data)
{
	pid_t process;
	int end;

	end = 0;
	if (cmds[pos + 1] == NULL)
	{
		if (pos > 0)
			is_pipeline(cmds, pos, in_fd, data);
		else
			is_command_alone(cmds, pos, in_fd, data);
		while (end != -1)
			end = wait(NULL);
	}
	else
	{
		pipe(data->pipe);
		process = fork();
		if (process == 0)
			exec_fils(cmds, pos, in_fd, data);
		else
			exec_papa(cmds, pos, in_fd, data);
	}
	return (EXIT_SUCCESS);
}

int exec_hub(t_data *data)
{
	int i;
	int x;
	char ***commands;
	char **split;

	i = 0;
	split = ft_split_spec(data->line, '|');
	commands = malloc(sizeof(char **) * (tabsize(split) + 1));
	while (i < tabsize(split))
	{
		x = 0;
		if (redirection_hub(data, &split[i], i) == EXIT_FAILURE)
		{
			free_splitted(split, 0);
			free(commands);
			return (EXIT_FAILURE);
		}
		commands[i] = ft_split_spec(split[i], ' ');
		while (commands[i][x])
			remove_quotes(&commands[i][x++]);
		i++;
	}
	commands[i] = NULL;
	if (exec_pipeline(commands, 0, STDIN_FILENO, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < tabsize(split))
		free_splitted(commands[i++], 0);
	free(commands);
	free_splitted(split, 0);
	i = 0;
	while (i < tabsize(split))
	{
		ft_lstclear_redirect(&data->tPipe[i].redirect, free);
		i++;
	}
	return (EXIT_SUCCESS);
}