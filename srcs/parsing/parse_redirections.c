
#include "../../includes/minishell.h"

int		is_isspace(char c)
{
	if ((c) && (c == '\f' || c == '\n' || c == '\v' || c == '\t' || c == '\r' || c == ' '))
		return (1);
	return (0);
}

int		is_separator(char c)
{
	if (is_isspace(c) ||  c == '>' || c == '<')
		return (1);
	return (0);
}

void	debug(t_data *data)
{
	int x;

	x = 0;
	while (data->redirects[x].pos != -1)
	{
		printf("index : %d\n", x);
		printf("pos   : %d\n", data->redirects[x].pos);
		printf("type  : %d\n", data->redirects[x].type);
		printf("way   : %d\n", data->redirects[x].way);
		printf("file  : %s\n", data->redirects[x].file);
		printf("\n");
		x++;
	}
}

int		get_filename(t_data *data, int x, int i, char *str)
{
	int j;
	int stop;
	char *file;

	j = 0;
	stop = 0;
	while (str[j] && is_isspace(str[j]))
		j++;
	while (str[j + stop] && !is_separator(str[j + stop]))
		stop++;
	file = ft_substr(str, j, stop);
	data->redirects[x].start = i + j + 1;
	data->redirects[x].file = file;
	return (1);
}

int		get_filename_reverse(t_data *data, int x, int i, char *str)
{
	int j;
	int stop;
	char *file;

	stop = 0;
	j = i - 1;
	while (j > 0 && is_isspace(data->line[j]))
		j--;
	while ((j - stop > 0) && data->line[j - stop] && !is_separator(data->line[j - stop]))
		stop++;
	file = ft_substr(data->line, j - stop == 0 ? j - stop : j - stop + 1, stop);
	data->redirects[x].start = j - stop == 0 ? j - stop : j - stop + 1;
	data->redirects[x].file = file;
	return (1);
}

int		is_redirect(t_data *data, int x, int *i, char *str)
{
	if (str[0] && str[0] == '>')
	{
		data->redirects[x].way = RIGHT;
		if (str[1] && str[1] == '>')
		{
			(*i)++;
			data->redirects[x].type = DOUBLE_AQUOTE;
			get_filename(data, x, (*i), str + 2);
			return (1);
		}
		data->redirects[x].type = SIMPLE_AQUOTE;
		get_filename(data, x, (*i), str + 1);
		return (1);
	}
	if (str[0] && str[0] == '<')
	{
		data->redirects[x].way = LEFT;
		data->redirects[x].type = SIMPLE_AQUOTE;
		get_filename_reverse(data, x, (*i), str);
		return (1);
	}
	return (0);
}

int		parse_redirect(t_data *data)
{
	int i;

	i = 0;
	while (data->redirects[x].pos != -1)
	{

	}
	return (0);
}

int		get_redirections(t_data *data)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (data->line[i])
	{
		if (is_redirect(data, x, &i, &data->line[i]))
			data->redirects[x++].pos = i;
		i++;
	}
	data->redirects[x].pos = -1;
	data->redirects[x].type = -1;
	data->redirects[x].way = -1;
	parse_redirect(data);
	debug(data);
	printf("%s\n", data->line);
	return (1);
}