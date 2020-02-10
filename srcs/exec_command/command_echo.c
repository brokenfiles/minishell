
#include "../../includes/minishell.h"

int		exec_echo(t_data *data)
{
	int	x;
	int	is_n;
	int	len;

	is_n = 0;
	x = 0;
	if ((len = tabsize(data->arguments)) >= 1 && ft_strcmp(data->arguments[0], "-n") == 0)
		is_n = 1;
	if (is_n)
		x++;
	while (data->arguments[x])
		len - 1 != x ? ft_printf("%s ", data->arguments[x++]) : ft_printf("%s", data->arguments[x++]);
	if (!is_n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
