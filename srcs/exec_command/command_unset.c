
#include "../../includes/minishell.h"

int		get_unset_tab(t_data *data, int i)
{
	char	**str;
	int		j;
	int		x;

	x = 0;
	if (!(str = malloc(sizeof(char*) * (tabsize(data->env)))))
<<<<<<< HEAD
		return (0);
	j = 0;
	while (x < i)
	{
		str[x] = ft_strdup(data->env[j]);
		x++;
		j++;
	}
	j++;
	while (data->env[j])
	{
		str[x] = ft_strdup(data->env[j]);
		x++;
		j++;
	}
	str[x] = 0;
	free_splitted(data->env, 0);
	data->env = str;
	return (1);
=======
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
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
}

int		exec_unset(t_data *data, char **cmds)
{
<<<<<<< HEAD
	int		i;
	int		index;
	char	**split;

	index = 0;
	i = 0;
	data->arguments = cmds + 1;
	if (tabsize(data->arguments) < 1)
		return (EXIT_FAILURE);
	while (tabsize(data->env) > i && data->env[i])
	{
		split = ft_split(data->env[i], '=');
		if (ft_strcmp(split[0], data->arguments[index]) == 0)
		{
			if (ft_strlen(split[0]) == ft_strlen(data->arguments[index]))
			{
				get_unset_tab(data, i);
				if (data->arguments[index + 1])
				{
					free_splitted(split, 0);
					i = 0;
					index++;
					continue;
				}
			}
		}
		free_splitted(split, 0);
		i++;
		if (i >= tabsize(data->env) && data->arguments[index + 1])
		{
			i = 0;
			index++;
		}
=======
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
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	}
	return (EXIT_SUCCESS);
}