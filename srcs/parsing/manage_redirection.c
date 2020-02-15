#include "../../includes/minishell.h"

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

int		redirect_input(void)
{
	struct stat	buff;
	int			fd;
	int			ret;

	ret = stat("out", &buff);
	if (ret == -1 || S_ISDIR(buff.st_mode))
		return (EXIT_FAILURE);
	if (!(fd = open("out", O_RDONLY)))
		return (-1);
	if (dup2(fd, STDIN_FILENO) < 1)
		return (-1);
	return (fd);
}

int		exec_hub(t_data *data)
{
	/*int fds[2];
	fds[0] = dup(1);
	fds[1] = open("out", O_RDWR);
	dup2(fds[1], 1);

	run_command(data, exec_prog);

	dup2(fds[0], 1);
	close(fds[0]);
	close(fds[1]);*/

	char **split;
	char **cmds;
	int stds[1];
	int fd;
	int i;

	i = 0;
	split = ft_split(data->line, '|');
	while (split[i])
	{
		if (split[i + 1] == 0)
		{
			cmds = ft_split_spec(split[i], ' ');
			data->command = ft_strdup(cmds[0]);
			run_command(data, cmds);
		}
		else
		{
			cmds = ft_split_spec(split[i], ' ');
			data->command = ft_strdup(cmds[0]);
			stds[0] = dup(0);
			fd = redirect_input();
			run_command(data, cmds);
			stop_redirect(fd, stds[0], STDIN_FILENO);
			close(stds[0]);
		}
		free_splitted(cmds, 0);
		free(data->command);
		i++;
	}
	free_splitted(split, 0);
	return (EXIT_SUCCESS);
}