
#include "../../includes/minishell.h"

int		inc_shlvl(t_data *data)
{
	char	**cmds;
	char	*value;
	char	*env_value;

	env_value = get_env(data, "SHLVL");
	cmds = malloc(sizeof(char *) * 3);
	value = ft_itoa(ft_atoi(env_value) + 1);
	cmds[0] = ft_strdup("export");
	cmds[1] = ft_strjoin("SHLVL=", value);
	cmds[2] = NULL;
	exec_export(data, cmds);
	free(env_value);
	free(value);
	return (free_splitted(cmds, EXIT_SUCCESS));
}

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
		data->tpipe[index++].redirect = NULL;
}

void	reset_redirections(t_data *data)
{
	int	index;

	index = 0;
	while (index < REDIRECT_MAX)
	{
		if (data->tpipe[index].redirect != NULL)
			ft_lstclear_redirect(&data->tpipe[index].redirect, free);
		data->tpipe[index++].redirect = NULL;
	}
}

t_data	*init_struct(char **env)
{
	t_data	*data;

	if (!(data = malloc(sizeof(struct s_data))))
		return (NULL);
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (NULL);
	if ((set_env(data, env)) == EXIT_FAILURE)
		return (NULL);
	if ((inc_shlvl(data)) == EXIT_FAILURE)
		return (NULL);
	init_pipe(data);
	data->line = NULL;
	return (data);
}
