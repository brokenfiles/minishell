
#include "../../includes/minishell.h"

int		is_redirect(t_data *data, int x, int *i, char *str)
{
	if (str[0] && str[0] == '>')
	{
		data->redirects[x].way = RIGHT;
		if (str[1] && str[1] == '>')
		{
			(*i)++;
			data->redirects[x].type = DOUBLE_AQUOTE;
			return (1);
		}
		data->redirects[x].type = SIMPLE_AQUOTE;
		return (1);
	}
	if (str[0] && str[0] == '<')
	{
		data->redirects[x].way = LEFT;
		data->redirects[x].type = SIMPLE_AQUOTE;
		return (1);
	}
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
		printf("\n");
		x++;
	}
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
		{
			data->redirects[x].pos = i;
			x++;
		}
		i++;
	}
	data->redirects[x].pos = -1;
	data->redirects[x].type = -1;
	data->redirects[x].way = -1;
	debug(data);
	return (1);
}