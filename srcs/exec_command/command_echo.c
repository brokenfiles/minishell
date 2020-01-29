
#include "../../includes/minishell.h"

int		get_echo(t_data *data)
{
	int	index;

	index = 0;
	while (data->arguments[index])
	{
		if (data->arguments[index] != '"')
			ft_putchar(data->arguments[index]);
		index++;
	}
//	ft_putstr(data->arguments);
	ft_putstr("\n");
	return (1);
}