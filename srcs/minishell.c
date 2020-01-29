
#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	data = init_struct(env);
	ft_putstr(PRE_LINE);
	while (get_next_line(0, &(data->line)) > 0)
	{
		replace_env(data);
		parse_line(data);
		ft_putstr(PRE_LINE);
		free(data->line);
	}
	free(data->line);
	return (EXIT_SUCCESS);
}