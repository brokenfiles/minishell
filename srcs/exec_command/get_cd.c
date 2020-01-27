
#include "../../includes/minishell.h"

int		get_cd(t_data *data)
{
	int index;
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (0);
	printf("%s\n", data->cwd);
	if (chdir("~/Cursus") == -1)
	printf("%s\n", data->cwd);
	index = 0;
	ft_putstr("CDCD\n");
	return (1);
}
