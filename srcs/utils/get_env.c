#include "../../includes/minishell.h"

char	*get_env_str(t_data *data, char *temp)
{
	int i;
	char **split;
	char *ret;

	i = 0;
	while (data->env[i])
	{
		split = ft_split(data->env[i], '=');
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
		i++;
	}
	return (NULL);
}