
#include "../../includes/minishell.h"

int		get_pwd(t_data *data)
{
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (0);
	ft_printf("%s\n", data->cwd);
	return (1);
}
