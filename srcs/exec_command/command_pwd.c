
#include "../../includes/minishell.h"

int		exec_pwd(t_data *data)
{
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (EXIT_FAILURE);
	ft_printf("%s\n", data->cwd);
	return (EXIT_SUCCESS);
}
