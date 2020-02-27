#include "../../includes/minishell.h"

int		exec_child(char ***cmds, int pos, int in_fd, t_data *data)
{
	close(data->pipe[0]);
	redirect(in_fd, STDIN_FILENO);
	if (is_right_arrow(data->tpipe[pos].redirect))
		data->fd[1] = handle_right_arrow(data->tpipe[pos].redirect);
	if (is_left_arrow(data->tpipe[pos].redirect))
	{
		if (handle_left_arrow(data, data->tpipe[pos].redirect, 1)
			== EXIT_FAILURE)
			exit(EXIT_FAILURE);
	}
	if (!is_right_arrow(data->tpipe[pos].redirect) &&
	!is_left_arrow(data->tpipe[pos].redirect))
		redirect(data->pipe[1], 1);
	close(data->pipe[1]);
	run_command(data, cmds[pos]);
	exit(EXIT_SUCCESS);
}

int		exec_parent(char ***cmds, int pos, int in_fd, t_data *data)
{
	if (pos > 0)
		close(in_fd);
	close(data->pipe[1]);
	if (exec_pipeline(cmds, pos + 1, data->pipe[0], data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		is_built_in(char *str)
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
	return (0);
}

int		redirect_output(t_redirect *redirect)
{
	int	fd;

	if (!(fd = open(redirect->file, redirect->type == DOUBLE_AQUOTE ?
	O_RDWR | O_CREAT | O_APPEND
				: O_RDWR | O_CREAT | O_TRUNC, 0644)))
		return (-1);
	if (dup2(fd, STDOUT_FILENO) < 1)
		return (-1);
	return (fd);
}

void	redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			close(oldfd);
	}
}
