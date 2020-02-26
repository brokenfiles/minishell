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

<<<<<<< HEAD
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
=======
void	error_command_nf(char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	write_preline(t_data *data)
{
	if (isatty(0))
	{
		ft_printf(PRE_LINE, ((get_last_char(data->cwd, '/') != -1
		&& ft_strlen(data->cwd) != 1) ?
		data->cwd + get_last_char(data->cwd, '/') + 1 : data->cwd));
	}
}

int		count_char(char *str, char c)
{
	int	index;
	int	counter;
	int	quotes[2];

	init_int(&index, &counter, 0, 0);
	init_int(&quotes[0], &quotes[1], 0, 0);
	while (str[index])
	{
		if (str[index] == '"' && !quotes[0])
			quotes[1] = !quotes[1];
		if (str[index] == '\'' && !quotes[1])
			quotes[0] = !quotes[0];
		if (str[index] == c && (!quotes[0] && !quotes[1]))
			counter++;
		index++;
	}
	return (counter);
}

int		remove_quotes(char **str)
{
	int		i;
	int		x;
	int		quotes[2];
	char	*new;

	x = ft_strlen(*str) - (count_char(*str, '\'') + count_char(*str, '"'));
	if (!(new = ft_strnew(x)))
		return (-1);
	init_int(&i, &x, 0, 0);
	init_int(&quotes[0], &quotes[1], 0, 0);
	while ((*str)[i])
	{
		if ((*str)[i] == '"' && !quotes[0])
			quotes[1] = !quotes[1];
		if ((*str)[i] == '\'' && !quotes[1])
			quotes[0] = !quotes[0];
		if (((*str)[i] != '"' && (*str)[i] != '\'') || (quotes[1] && (*str)[i] == '\'') || (quotes[0] && (*str)[i] == '"'))
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
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