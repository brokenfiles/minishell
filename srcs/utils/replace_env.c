#include "../../includes/minishell.h"

int get_new_line(t_data *data, char *env, int index, int size)
{
	char	*new_line;
	char	**splitted;

	splitted = ft_split(env, '=');
	new_line = ft_strnew(ft_strlen(data->line) - size + ft_strlen(splitted[1]));
	new_line = ft_strncat(new_line, data->line, index);
	new_line = ft_strncat(new_line, splitted[1], ft_strlen(splitted[1]));
	new_line = ft_strncat(new_line, &data->line[index + size], ft_strlen(data->line) - index - size);
	free(data->line);
	data->line = new_line;
	return (free_splitted(splitted, 0));
}

int get_var_env(t_data *data, char *str, int *index)
{
	int		i;
	int		len;
	char	**split;
	char	*temp;

	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	temp = ft_substr(str, 0, i);
	while (data->env[(*index)])
	{
		split = ft_split(data->env[(*index)], '=');
		if (ft_strncmp(temp, split[0], ft_strlen(split[0])) == 0)
		{
			len = ft_strlen(split[0]);
			if (len == (int)ft_strlen(temp))
				return (fsp(split, temp, len, NULL));
			free_splitted(split, 0);
		} else
			free_splitted(split, 0);
		(*index)++;
	}
	free(temp);
	return (0);
}

int	is_interrogation(t_data *data, int x)
{
	char *new_line;
	char *itoa;
	int len;

	itoa = ft_itoa(data->last_return);
	len = ft_strlen(itoa);
	if (!(new_line = ft_strnew(ft_strlen(data->line) + ft_strlen(itoa) - 1)))
		return (0);
	new_line = ft_strncat(new_line, data->line, x - 1);
	new_line = ft_strncat(new_line, itoa, len);
	new_line = ft_strncat(new_line, &data->line[x + len], ft_strlen(data->line) - x - 1);
	free(data->line);
	free(itoa);
	data->line = new_line;
	return (1);
}

int is_invalid_env(t_data *data, int x)
{
	int i;
	char *new_line;
	char *str;
	int empty;

	empty = 0;
	str = &data->line[x];
	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	if (str[i] != '\0' && str[i] == '?')
		return (is_interrogation(data, x));
	str = NULL;
	empty = i == 0 ? 1 : 0;
	if (!(new_line = ft_strnew(ft_strlen(data->line) + empty - i)))
		return (0);
	new_line = ft_strncat(new_line, data->line, x - 1);
	if (empty)
		new_line = ft_strncat(new_line, "$", 1);
	new_line = ft_strncat(new_line, &data->line[x + i], ft_strlen(data->line) - x - i);
	free(data->line);
	data->line = new_line;
	return (1);
}

int replace_env(t_data *data)
{
	int	i;
	int	index;
	int	temp;

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
				i++;
				continue;
			}
			get_new_line(data, data->env[index], i, temp + 1);
		}
		i++;
	}
	return (1);
}