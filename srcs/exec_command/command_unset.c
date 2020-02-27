
#include "../../includes/minishell.h"

int		is_in_env(t_data *data, char *env_line)
{
	int	index;

	index = 0;
	while (data->env[index])
	{
		if (ft_strcmp(data->env[index], env_line) == 0 &&
		ft_strlen(data->env[index]) == ft_strlen(env_line))
			return (1);
		index++;
	}
	return (0);
}

int		remove_env(t_data *data, char *env_line)
{
	char	**new_env;
	int		index;
	int		index2;
	char	*tmp;

	index = 0;
	index2 = 0;
	if (!(new_env = malloc(sizeof(char *) * tabsize(data->env) +
			1 + (is_in_env(data, env_line) ? -1 : 0))))
		return (EXIT_FAILURE);
	while (data->env[index])
	{
		if (!(tmp = ft_substr(data->env[index], 0,
				get_first_char(data->env[index], '='))))
			return (EXIT_FAILURE);
		if (ft_strcmp(tmp, env_line))
			new_env[index2++] = ft_strdup(data->env[index]);
		free(tmp);
		index++;
	}
	new_env[index2] = NULL;
	free_splitted(data->env, 0);
	data->env = new_env;
	return (EXIT_SUCCESS);
}

int		exec_unset(t_data *data, char **cmds)
{
	int		index;

	index = 0;
	data->arguments = cmds + 1;
	if (tabsize(data->arguments) < 1)
		return (EXIT_SUCCESS);
	while (data->arguments[index])
	{
		if (remove_env(data, data->arguments[index]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
