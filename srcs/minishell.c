
#include "../includes/minishell.h"

void	cancel()
{
	ft_printf("\n\n");
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	data = init_struct(env);
	ft_printf(PRE_LINE, ((get_last_char(data->cwd, '/') != -1 && ft_strlen(data->cwd) != 1) ? data->cwd + get_last_char(data->cwd, '/') + 1 : data->cwd));
	signal(SIGINT, );
	while (get_next_line(0, &(data->line)) > 0)
	{
		replace_env(data);
		parse_line(data);
		free(data->line);
		data->line = NULL;
		ft_printf(PRE_LINE, ((get_last_char(data->cwd, '/') != -1 && ft_strlen(data->cwd) != 1) ? data->cwd + get_last_char(data->cwd, '/') + 1 : data->cwd));
	}
	free(data->line);
	return (EXIT_SUCCESS);
}