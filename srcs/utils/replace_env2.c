#include "../../includes/minishell.h"

int		is_invalid_env(t_data *data, int x)
{
	int		i;
	char	*new_line;
	char	*str;
	int		empty;

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
	new_line = ft_strncat(new_line, &data->line[x + i],
			ft_strlen(data->line) - x - i);
	free(data->line);
	data->line = new_line;
	return (1);
}

int		replace_env(t_data *data)
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
