
#include "../../includes/minishell.h"

int		ft_bigstrlen(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		get_unset_tab(t_data *data, int i, char *unset)
{
	char **str;
	int j;
	int x;

	x = 0;
	if (!(str = malloc(sizeof(char*) * (ft_bigstrlen(data->env)))))
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
}

int		get_unset(t_data *data)
{
	int i;
	int index;
	char **split;

	index = 0;
	i = 0;
	if (ft_bigstrlen(data->arguments) < 1)
		return (0);
	while (ft_bigstrlen(data->env) > i && data->env[i])
	{
		split = ft_split(data->env[i], '=');
		if (ft_strcmp(split[0], data->arguments[index]) == 0)
		{
			if (ft_strlen(split[0]) == ft_strlen(data->arguments[index]))
			{
				get_unset_tab(data, i, split[0]);
				if (data->arguments[index + 1])
				{
					free_splitted(split, 0);
					i = 0;
					index++;
					continue;
				}
			}
			//TODO : WHILE STILL BAD VAR
		}
		free_splitted(split, 0);
		i++;
		
	}
	return (1);
}