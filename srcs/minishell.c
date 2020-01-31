
#include "../includes/minishell.h"

t_data	*g_data;

void	cancel()
{
	ft_putchar('\n');
	ft_printf(PRE_LINE, ((get_last_char(g_data->cwd, '/') != -1 && ft_strlen(g_data->cwd) != 1) ? g_data->cwd + get_last_char(g_data->cwd, '/') + 1 : g_data->cwd));
}

int	main(int ac, char **av, char **env)
{
	g_data = init_struct(env);
	ft_printf(PRE_LINE, ((get_last_char(g_data->cwd, '/') != -1 && ft_strlen(g_data->cwd) != 1) ? g_data->cwd + get_last_char(g_data->cwd, '/') + 1 : g_data->cwd));
	signal(SIGINT, cancel);
	while (get_next_line(0, &(g_data->line)) > 0)
	{
		ft_printf("\033[0;0m");
		replace_env(g_data);
		parse_line(g_data);
		free(g_data->line);
		g_data->line = NULL;
		ft_printf(PRE_LINE, ((get_last_char(g_data->cwd, '/') != -1 && ft_strlen(g_data->cwd) != 1) ? g_data->cwd + get_last_char(g_data->cwd, '/') + 1 : g_data->cwd));
	}
	free(g_data->line);
	return (EXIT_SUCCESS);
}