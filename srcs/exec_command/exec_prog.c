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
			? quit("permission denied", free_splitted(arguments, EXIT_FAILURE)) : 0;
	else if (pid < 0)
		quit("failed to fork", free_splitted(arguments, EXIT_FAILURE));
	else
		wait(&pid);
	free_splitted(arguments, 0);
	return (EXIT_SUCCESS);
}
