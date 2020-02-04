
#include "../../includes/minishell.h"

int		get_echo(t_data *data)
{
	int x;
	int is_n;

	is_n = 0;
	x = 0;
	if (ft_bigstrlen(data->arguments) >= 1 && ft_strcmp(data->arguments[0], "-n") == 0)
		is_n = 1;
	if (is_n)
		x++;
	while (data->arguments[x])
		ft_printf("%s ", data->arguments[x++]);
	if (!is_n)
		ft_putchar('\n');
	return (1);
}
