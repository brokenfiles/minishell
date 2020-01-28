
#include "../../includes/minishell.h"

int		get_new_line(t_data *data, char *env, int index, int size)
{
	char *new_line;
	char **splitted;
	int i;
	int j;

	i = 0;
	splitted = ft_split(env, '=');
	new_line = ft_strnew(ft_strlen(data->line) - size + ft_strlen(splitted[1]));

	while (i < index && data->line[i])
	{
		new_line[i] = data->line[i];
		i++;
	}
	new_line = ft_strncat(new_line, splitted[1], ft_strlen(splitted[1]));
	new_line = ft_strncat(new_line, &data->line[i + ft_strlen(env)], ft_strlen(data->line) - i - ft_strlen(splitted[1]));
	printf("%s\n", new_line);
	return (0);
}

int		replace_env(t_data *data)
{
	int i;
	int index;
	int temp;
	char *env;
	char **splited;
	char *new_line;

	temp = 0;
	index = 0;
	i = 0;
	while (data->line[i])
	{
		if (data->line[i] == '$')
		{
			while (data->line[i + temp] != ' ' && data->line[i + temp])
				temp++;
			env = ft_substr(data->line, i + 1, temp - 1);
			while (data->env[index])
			{
				if (ft_strnstr(data->env[index], env, ft_strlen(env)))
				{
					get_new_line(data, data->env[index], i, temp);
					break;
				}
				index++;
			}
			i = i + ft_strlen(env);
		}
		i++;
	}
//	printf("%s\n", env);
	return (0);
}