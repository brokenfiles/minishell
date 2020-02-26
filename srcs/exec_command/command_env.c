
#include "../../includes/minishell.h"

int		exec_env(t_data *data, char **cmds)
{
	char	**tmp;
	char	*view;

	tmp = data->env;
	if (!tmp || !*tmp)
		return (EXIT_FAILURE);
	if (tabsize(cmds) > 1)
	{
		ft_printf("env: '%s': no such file or directory\n", cmds[1]);
		return (EXIT_FAILURE);
	}
	while (*tmp)
	{
		view = get_without_quotes(*(tmp++));
		ft_printf("%s\n", view);
		free(view);
	}
	return (EXIT_SUCCESS);
}