
#include "../../includes/minishell.h"

char	*get_only_export_var(char *str)
{
	int i;
	int x;
	char *new;

	x = 0;
	i = 0;
	while (data->arguments[x][i] && ft_isalnum(data->arguments[x][i]))
		i++;
	if (data->arguments[x][i] && data->arguments[x][i] == '=')
		i++;
	else
		return (NULL);
	while (data->arguments[x][i] && ft_isprint(data->arguments[x][i]))
		i++;
	if (!(new = ft_substr(str, 0, i)))
		return (NULL);
	return (new);
}

int		get_export(t_data *data)
{
	int i;
	char *export;

	x = 0;
	while (data->arguments[x])
	{
		if ((export = get_only_export_var(data->arguments[x])) != NULL)
		{
			add_export(export);

		}
		x++;
	}
	return (1);
}