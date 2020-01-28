#include "../../includes/minishell.h"

int	exec_prog(t_data *data)
{
	char	*path;
	char	**arguments;
	pid_t	pid;

	arguments = ft_split(data->line, ' ');
	path = data->command + 2;
	pid = fork();
	if (pid == 0)
		execve(path, arguments, data->env) == -1 \
			? quit("No such file or directory", 1) : 0;
	else if (pid < 0)
		quit("Failed to fork", 1);
	else
		wait(&pid);
	free(arguments);
	return (1);
}