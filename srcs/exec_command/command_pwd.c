
#include "../../includes/minishell.h"

int		exec_pwd(t_data *data)
{
	ft_printf("%s\n", data->cwd);
	return (EXIT_SUCCESS);
}
