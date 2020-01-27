#include "../../includes/minishell.h"

int		get_env(t_data *data)
{
	int i;

	i = 0;
	while (data->env[i])
	{
		ft_putstr(data->env[i++]);
		ft_putchar('\n');
	}
	return (1);
}