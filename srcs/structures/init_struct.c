
#include "../../includes/minishell.h"

int set_env(t_data *data, char **str)
{
	int i;
	int size;
	char **new;

	i = 0;
	size = ft_bigstrlen(str);
	if (!(new = malloc(sizeof(char*) * (size + 1))))
		return (0);
	new[size] = 0;
	while (i < size)
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	data->env = new;
	return (1);
}

t_data	*init_struct(char **env)
{
	t_data	*data;

	if (!(data = malloc(sizeof(struct s_data))))
		return (NULL);
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (NULL);
	if (!(set_env(data, env)))
		return (NULL);
	data->line = NULL;
	return (data);
}