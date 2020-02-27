
#include "../../includes/minishell.h"

int		sort_env_export(t_data *data)
{
	int		index;
	char	**temp;

	if (!(temp = malloc(sizeof(char*) * (tabsize(data->env) + 1))))
		return (EXIT_FAILURE);
	temp[tabsize(data->env)] = 0;
	index = 0;
	while (index++ < tabsize(data->env))
		temp[index - 1] = ft_strdup(data->env[index - 1]);
	index = 0;
	while (temp[index] && temp[index + 1])
	{
		if (ft_strcmp(temp[index], temp[index + 1]) > 0)
		{
			ft_swap((void **)&temp[index], (void **)&temp[index + 1]);
			index = 0;
		}
		else
			index++;
	}
	display_export_alone(temp);
	return (free_splitted(temp, EXIT_SUCCESS));
}
