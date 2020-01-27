
#include "../../includes/minishell.h"

int		get_pwd(t_data *data)
{
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (0);
	ft_putstr(data->cwd);
	ft_putchar('\n');
	return (1);
}
