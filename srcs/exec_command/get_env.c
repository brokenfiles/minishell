
#include "../../includes/minishell.h"

int		get_env(t_data *data)
{
	int i;

	i = 0;
	while (data->env[i])
<<<<<<< HEAD
		ft_printf("%s\n", data->env[i++]));
=======
		ft_printf("%s\n", data->env[i++]);
>>>>>>> 120353a0627a3ef21aa49f3b5abce57fe922543a
	return (1);
}