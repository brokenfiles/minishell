
#include "../../includes/minishell.h"

int		get_echo(t_data *data)
{
	int		index;
	char	*tmp;

	index = 0;
	while (data->arguments[index])
	{
		tmp = data->arguments[index];
		data->arguments[index] = ft_strtrim(data->arguments[index], "\"'");
		free(tmp);
		ft_putstr(data->arguments[index]);
		ft_putstr(" ");
		index++;
	}
//	ft_putstr(data->arguments);
	ft_putstr("\n");
	return (1);
}