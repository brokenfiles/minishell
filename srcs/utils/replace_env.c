#include "../../includes/minishell.h"

char	*get_first_equal(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '=')
			return (ft_strdup(&str[index + 1]));
		index++;
	}
	return (NULL);
}

int		get_new_line(t_data *data, char *env, int index, int size)
{
	char	*new_line;
	char	*content;

	content = get_first_equal(env);
	new_line = ft_strnew(ft_strlen(data->line) - size + ft_strlen(content));
	new_line = ft_strncat(new_line, data->line, index);
	new_line = ft_strncat(new_line, content, ft_strlen(content));
	new_line = ft_strncat(new_line, &data->line[index + size],
			ft_strlen(data->line) - index - size);
	free(data->line);
	data->line = new_line;
	free(content);
	return (EXIT_SUCCESS);
}

int		get_var_env(t_data *data, char *str, int *index)
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
		}
		else
			free_splitted(split, 0);
		(*index)++;
	}
	free(temp);
	return (0);
}

int		is_interrogation(t_data *data, int x)
{
	char	*new_line;
	char	*itoa;
	int		len;

	itoa = ft_itoa(data->last_return);
	len = ft_strlen(itoa);
	if (!(new_line = ft_strnew(ft_strlen(data->line) + ft_strlen(itoa) - 1)))
		return (0);
	new_line = ft_strncat(new_line, data->line, x - 1);
	new_line = ft_strncat(new_line, itoa, len);
	new_line = ft_strncat(new_line, &data->line[x + len],
			ft_strlen(data->line) - x - 1);
	free(data->line);
	free(itoa);
	data->line = new_line;
	return (1);
}
