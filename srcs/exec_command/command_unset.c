
#include "../../includes/minishell.h"

int		get_unset_tab(t_data *data, int i, char *unset)
{
	char **str;
	int i;
	int x;

	i = 0;
	x = 0;
	while (data->env[i])
		i++;
	if (!(str = malloc(sizeof(char*) * (i))))
		return (0);
	while (x < i)
	{
		
		x++;
	}
}

int		get_unset(t_data *data)
{
	int i;
	int index;
	char **split;

	index = 0;
	i = 0;
	while (data->env[i])
	{
		split = ft_split(data->env[i], '=')
		if (ft_strcmp(split[0], data->arguments[index]) == 0)
		{
			if (ft_strlen(split[0]) == ft_strlen(data->arguments[0]))
			{
				get_unset_tab(data, i, split[0]);
			}
		}
		i++;
	}
}