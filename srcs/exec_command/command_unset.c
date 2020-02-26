
#include "../../includes/minishell.h"

int		get_unset_tab(t_data *data, int i)
{
	char	**str;
	int		j;
	int		x;

	x = 0;
	if (!(str = malloc(sizeof(char*) * (tabsize(data->env)))))
		return (EXIT_FAILURE);
	j = 0;
	while (x < i)
		str[x++] = ft_strdup(data->env[j++]);
	j++;
	while (data->env[j])
		str[x++] = ft_strdup(data->env[j++]);
	str[x] = 0;
	free_splitted(data->env, 0);
	data->env = str;
	return (EXIT_SUCCESS);
}

int		exec_unset(t_data *data, char **cmds)
{
	int		index[2];
	char	**split;

	init_int(&index[0], &index[1], 0, 0);
	data->arguments = cmds + 1;
	if (tabsize(data->arguments) < 1)
		return (EXIT_FAILURE);
	while (tabsize(data->env) > index[0] && data->env[index[0]])
	{
		if (!(split = ft_split(data->env[index[0]], '=')))
			return (EXIT_FAILURE);
		if (ft_strcmp(split[0], data->arguments[index[1]]) == 0 &&
			ft_strlen(split[0]) == ft_strlen(data->arguments[index[1]]))
		{
			if ((get_unset_tab(data, index[0])) == EXIT_FAILURE)
				return (free_splitted(split, EXIT_FAILURE));
			if (data->arguments[index[1] + 1])
			{
				free_splitted(split, 0);
				init_int(&index[0], &index[1], 0, index[1] + 1);
				continue;
			}
		}
		free_splitted(split, 0);
		index[0]++;
		if (index[0] >= tabsize(data->env) && data->arguments[index[1] + 1])
			init_int(&index[0], &index[1], 0, index[1] + 1);
	}
	return (EXIT_SUCCESS);
}