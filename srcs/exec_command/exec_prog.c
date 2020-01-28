#include "../../includes/minishell.h"

int	exec_prog(t_data *data)
{
	char	**arguments;
	pid_t	pid;
	int		fd;

	if ((fd = open(data->command, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	arguments = ft_split(data->line, ' ');
	close(fd);
	pid = fork();
	if (pid == 0)
		execve(data->command, arguments, data->env) == -1 \
			? quit("permission denied", EXIT_FAILURE) : 0;
	else if (pid < 0)
		quit("pailed to fork", EXIT_FAILURE);
	else
		wait(&pid);
	free(arguments);
	return (EXIT_SUCCESS);
}
