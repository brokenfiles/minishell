#include "../../includes/minishell.h"

char	*get_env(t_data *data, char *temp)
{
	int		index;
	char	**split;
	char	*ret;

	index = 0;
	while (data->env[index])
	{
		if (!(split = ft_split(data->env[index], '=')))
			return (NULL);
		if (ft_strcmp(temp, split[0]) == 0)
		{
			if (ft_strlen(temp) == ft_strlen(split[0]))
			{
				ret = ft_strdup(split[1]);
				free_splitted(split, 0);
				return (ret);
			}
		}
		free_splitted(split, 0);
		index++;
	}
	return (NULL);
}
