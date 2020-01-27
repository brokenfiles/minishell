
#include "../../includes/minishell.h"

int		get_env(t_data *data)
{
	int i;

	i = 0;
	while (data->env[i])
		ft_printf("%s\n", data->env[i++]);
	return (1);
}