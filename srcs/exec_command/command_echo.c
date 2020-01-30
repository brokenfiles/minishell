
#include "../../includes/minishell.h"

int		get_echo(t_data *data)
{
	int		index;

	index = 0;
	while (data->arguments[index])
	{
		ft_putstr(data->arguments[index]);
		ft_putstr(" ");
		index++;
	}
//	ft_putstr(data->arguments);
	ft_putstr("\n");
	return (1);
}