
#include "../../includes/minishell.h"

<<<<<<< HEAD
int		exec_env(t_data *data)
=======
int		exec_env(t_data *data, char **cmds)
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
{
	char	**tmp;

	tmp = data->env;
	if (!tmp || !*tmp)
		return (EXIT_FAILURE);
<<<<<<< HEAD
=======
	if (tabsize(cmds) > 1)
	{
		ft_printf("env: '%s': no such file or directory\n", cmds[1]);
		return (EXIT_FAILURE);
	}
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	while (*tmp)
		ft_printf("%s\n", *(tmp++));
	return (EXIT_SUCCESS);
}