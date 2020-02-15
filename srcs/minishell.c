
#include "../includes/minishell.h"

t_data	*g_data;

void	sig_handler()
{
	ft_putchar('\n');
	write_preline(g_data);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	g_data = init_struct(env);
	write_preline(g_data);
	signal(SIGINT, sig_handler);
	while ((get_next_line(0, &(g_data->line)) > 0))
	{
		ft_printf("\033[0;0m");
		replace_env(g_data);
		parse_line(g_data);
//		ft_lstadd_front(&g_data->history, ft_lstnew((char *)ft_strdup(g_data->line)));
		free(g_data->line);
		g_data->line = NULL;
		write_preline(g_data);
	}
	free(g_data->line);
	return (EXIT_SUCCESS);
}
