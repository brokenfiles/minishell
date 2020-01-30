
#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	data = init_struct(env);
	ft_printf("(\033[0;32m%s\033[0;0m) \033[0;33m➜ \033[0;0m", data->cwd);
	while (get_next_line(0, &(data->line)) > 0)
	{
		replace_env(data);
		parse_line(data);
		free(data->line);
		data->line = NULL;
		ft_printf("(\033[0;32m");
		ft_putstr(data->cwd);
		ft_printf("\033[0;0m) \033[0;33m➜ \033[0;0m");
	}
	free(data->line);
	return (EXIT_SUCCESS);
}