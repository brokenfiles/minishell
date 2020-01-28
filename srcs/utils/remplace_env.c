
#include "../../includes/minishell.h"

int		replace_env(t_data *data)
{
	int i;
	int index;
	int temp;
	char *env;

	temp = 0;
	i = 0;
	while (data->line[i])
	{
		if (data->line[i] == '$')
		{
			index = i;
			while (data->line[i + temp] != ' ' && data->line[i + temp])
				temp++;
			env = ft_substr(data->line, i + 1, temp - 1);
			//printf("%s\n", env);
			break;
//			while (data->env[i])
//			{
//				ft_strchr()
//			}
		}
		i++;
	}
	printf("%s\n", env);
	return (0);
}