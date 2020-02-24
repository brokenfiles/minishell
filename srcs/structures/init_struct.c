
#include "../../includes/minishell.h"

int set_env(t_data *data, char **str)
{
	int i;
	int size;
	char **new;

	i = 0;
	size = tabsize(str);
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

void	init_pipe(t_data *data)
{
	int	index;

	index = 0;
	while (index < REDIRECT_MAX)
	{
		data->tPipe[index].redirect = NULL;
		index++;
	}
}

void	reset_redirections(t_data *data)
{
	int	index;
	(void)data;
	index = 0;
	while (index < REDIRECT_MAX)
	{
		if (data->tPipe[index].redirect != NULL)
			ft_lstclear_redirect(&data->tPipe[index].redirect, free);
		data->tPipe[index].redirect = NULL;
		index++;
	}
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
	init_pipe(data);
	data->line = NULL;
	return (data);
}