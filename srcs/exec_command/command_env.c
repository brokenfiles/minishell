
#include "../../includes/minishell.h"

int		exec_env(t_data *data)
{
	char	**tmp;

	tmp = data->env;
	if (!tmp || !*tmp)
		return (EXIT_FAILURE);
	while (*tmp)
		ft_printf("%s\n", *(tmp++));
	return (EXIT_SUCCESS);
}