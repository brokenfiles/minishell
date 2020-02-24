#include "../includes/minishell.h"

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

int		redirect_output(t_redirect *redirect)
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
	/*int	index;
	int	index2;
	int	fd;
	int	fd2;
	int	stds[2];
	index = 0;

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
	reset_redirections(data, 1);*/
	run_command(data, exec_prog);
	return (EXIT_SUCCESS);
}