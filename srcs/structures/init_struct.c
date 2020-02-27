
#include "../../includes/minishell.h"

<<<<<<< HEAD
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

void	reset_redirections(t_data *data, int need_free)
=======
int		set_env(t_data *data, char **str)
{
	int		index;
	int		size;
	char	**new;

	index = 0;
	size = tabsize(str);
	if (!(new = malloc(sizeof(char*) * (size + 1))))
		return (EXIT_FAILURE);
	new[size] = 0;
	while (index++ < size)
		new[index - 1] = ft_strdup(str[index - 1]);
	data->env = new;
	return (EXIT_SUCCESS);
}

void	init_pipe(t_data *data)
{
	int	index;

	index = 0;
	while (index < REDIRECT_MAX)
		data->tPipe[index++].redirect = NULL;
}

void	reset_redirections(t_data *data)
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
{
	int	index;

	index = 0;
	while (index < REDIRECT_MAX)
	{
<<<<<<< HEAD
		if (data->redirects[index].pos != -1 && need_free)
			free(data->redirects[index].file);
		data->redirects[index].pos = -1;
		data->redirects[index].way = -1;
		data->redirects[index].file = NULL;
		data->redirects[index].previous = NULL;
		data->redirects[index++].type = -1;
=======
		if (data->tPipe[index].redirect != NULL)
			ft_lstclear_redirect(&data->tPipe[index].redirect, free);
		data->tPipe[index++].redirect = NULL;
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	}
}

t_data	*init_struct(char **env)
{
	t_data	*data;

	if (!(data = malloc(sizeof(struct s_data))))
		return (NULL);
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (NULL);
<<<<<<< HEAD
	if (!(set_env(data, env)))
		return (NULL);
	reset_redirections(data, 0);
=======
	if ((set_env(data, env)) == EXIT_FAILURE)
		return (NULL);
	init_pipe(data);
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	data->line = NULL;
	return (data);
}
