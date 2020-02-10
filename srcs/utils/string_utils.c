#include "../../includes/minishell.h"

int		get_next_char(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (str[index] == c)
		return (index);
	return (-1);
}

int		get_last_char(char *str, char c)
{
	int	index;
	int	last_char;

	last_char = -1;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			last_char = index;
		index++;
	}
	if (str[index] == c)
		last_char = index;
	return (last_char);
}

void	write_preline(t_data *data)
{
	ft_printf(PRE_LINE, ((get_last_char(data->cwd, '/') != -1
	&& ft_strlen(data->cwd) != 1) ?
	data->cwd + get_last_char(data->cwd, '/') + 1 : data->cwd));
}

int		remove_quotes(char **str)
{
	int i;
	int x;
	char *new;

	i = 0;
	x = 0;
	while ((*str)[i])
	{
		if (((*str)[i] && (*str)[i] != '\'' && (*str)[i] != '"'))
			x++;
		i++;
	}
	if (!(new = ft_strnew(x)))
		return (-1);
	i = 0;
	x = 0;
	while ((*str)[i])
	{
		if (((*str)[i] != '\'') && ((*str)[i] != '"'))
			new[x++] = (*str)[i];
		i++;
	}
	free(*str);
	*str = new;
	return (1);
}

int		tabsize(char **table)
{
	int	index;

	index = 0;
	if (!table)
		return (0);
	while (table[index])
		index++;
	return (index);
}