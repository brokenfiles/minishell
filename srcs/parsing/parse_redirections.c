
#include "../../includes/minishell.h"

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

int		get_next_pipe(t_data *data, int x, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '|')
		i++;
	data->redirects[x].file = ft_substr(str, 0, i);
	return (1);
}

int		get_filename_reverse(t_data *data, int x, int i)
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
		get_filename(data, x, (*i), str + 1);
		return (1);
	}
	if (str[0] && str[0] == '|')
	{
		data->redirects[x].way = NONE;
		data->redirects[x].type = PIPE;
		get_next_pipe(data, x, str + 1);
		return (1);
	}
	return (0);
}

int		get_redirections_len(t_data *data)
{
	int	index;

	index = 0;
	while (data->redirects[index].pos != -1)
		index++;
	return (index);
}

int		parse_redirect(t_data *data)
{
	int x;
	int temp;
	char *str;
	char *dup;
	char *join;

	x = get_redirections_len(data);
	while (x-- > 0)
	{
		if (data->redirects[x].type != PIPE)
		{
			temp = data->redirects[x].pos;
			str = ft_substr(data->line, 0, temp - ((data->redirects[x].type == DOUBLE_AQUOTE) ? 1 : 0));
//			temp = get_jump(data, temp, x);
			if (temp >= (int) ft_strlen(data->line))
				temp = ft_strlen(data->line);
			dup = ft_strdup(&data->line[temp]);
			join = ft_strjoin(str, dup);
			free(str);
			free(dup);
			free(data->line);
			data->line = join;
		}
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
//	printf("%s\n", data->line);
//	debug(data);
	return (1);
}