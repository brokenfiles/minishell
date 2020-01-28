
#include "../../includes/minishell.h"

int		get_new_line(t_data *data, char *env, int index, int size)
{
	char *new_line;
	char **splitted;
	char *temp;
	int i;
	int j;

	i = 0;
	splitted = ft_split(env, '=');
	new_line = ft_strnew(ft_strlen(data->line) - size + ft_strlen(splitted[1]));
	new_line = ft_strncat(new_line, data->line, index);
	new_line = ft_strncat(new_line, splitted[1], ft_strlen(splitted[1]));
	new_line = ft_strncat(new_line, &data->line[index + size], ft_strlen(data->line) - index - size);
	free(data->line);
	data->line = new_line;
	return (fnr(splitted, 0));
}

int		get_var_env(t_data *data, char *str, int *index)
{
	int i;
	int len;
	char **split;
	char *temp;

	i = 0;
	while (str[i] != '\0' && str[i] != '$' && str[i] != ' ' && str[i] != '"' && str[i] != '\'' && str[i] != '/')
		i++;
	temp = ft_substr(str, 0, i);
	while (data->env[(*index)])
	{
		split = ft_split(data->env[(*index)], '=');
		if (ft_strncmp(temp, split[0], ft_strlen(split[0])) == 0)
		{
			len = ft_strlen(split[0]);
			if (len == ft_strlen(temp))
				return (fnr(split, len));
			fnr(split, 0);
		}
		else
			fnr(split, 0);
		(*index)++;
	}
	return (0);
}

int		is_invalid_env(t_data *data, int x)
{
	int i;
	char *new_line;
	char *str;

	str = &data->line[x];
	i = 0;
	while (str[i] != '\0' && str[i] != '$' && str[i] != ' ' && str[i] != '"' && str[i] != '\'' && str[i] != '/')
		i++;
	if (!(new_line = ft_strnew(ft_strlen(data->line) - i)))
		return (0);
	new_line = ft_strncat(new_line, data->line, x - 1);
	new_line = ft_strncat(new_line, &data->line[x + i], ft_strlen(data->line) - x - i);
	free(data->line);
	data->line = new_line;
	return (1);
}

int		replace_env(t_data *data)
{
	int i;
	int index;
	int temp;
	char *env;
	char *new_line;

	index = 0;
	i = 0;
	while (data->line[i])
	{
		temp = 0;
		index = 0;
		if (data->line[i] == '$')
		{
			if ((temp = get_var_env(data, &data->line[i + 1], &index)) == 0)
			{
				is_invalid_env(data, i + 1);
				continue;
			}
			env = ft_substr(data->line, i + 1, temp);
			get_new_line(data, data->env[index], i, temp + 1);
		}
		i++;
	}
	return (1);
}