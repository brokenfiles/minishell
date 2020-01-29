
#include "../../includes/minishell.h"

t_data	*init_struct(char **env)
{
	t_data	*data;

	if (!(data = malloc(sizeof(struct s_data))))
		return (NULL);
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (NULL);
	data->line = NULL;
	data->env = env;
	return (data);
}