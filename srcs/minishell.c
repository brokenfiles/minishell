
#include "../includes/minishell.h"

t_data	*g_data;

void	sig_handler(int sig)
{
	(void)sig;
	ft_putchar('\n');
	write_preline(g_data);
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_data = init_struct(env);
	write_preline(g_data);
	signal(SIGINT, sig_handler);
	while ((get_next_line(0, &(g_data->line)) > 0))
	{
		replace_env(g_data);
		parse_line(g_data);
		free(g_data->line);
		g_data->line = NULL;
		write_preline(g_data);
	}
	free(g_data->line);
	return (EXIT_SUCCESS);
}
