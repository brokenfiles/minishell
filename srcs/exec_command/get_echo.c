
#include "../../includes/minishell.h"

int		get_echo(t_data *data)
{
	ft_putstr(data->arguments);
	ft_putstr("\n");
	return (1);
}