#include "../../includes/minishell.h"

int		exec_hub(t_data *data)
{
/*	char    ***commands;
	int     i;
	int     j;

	i = -1;
	if (!(commands = (char***)malloc(sizeof(char**) * ac)))
		return (0);
	commands[ac - 1] = NULL;
	while (++i < ac - 1)
		commands[i] = ft_strsplit(av[i + 1], ' ');
	exec_pipeline(commands, env, 0, STDIN_FILENO);


	char **split;

	split = ft_split(data)*/
	run_command(data, exec_prog);
	return (EXIT_SUCCESS);
}