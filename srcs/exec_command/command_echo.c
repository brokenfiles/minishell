
#include "../../includes/minishell.h"

int		get_echo(t_data *data)
{
	int		index;
	int		index2;
	int		backslash;
	char	*argument;
	int		no_newline;
	char	c;

	index = 0;
	backslash = 0;
	no_newline = 0;
	if (ft_bigstrlen(data->arguments) >= 1 && ft_strcmp(data->arguments[0], "-n") == 0)
		no_newline = 1;
	if (no_newline)
		index++;
	while (data->arguments[index])
	{
		argument = data->arguments[index];
		index2 = 0;
		while (argument[index2])
		{
			if (backslash == 1)
			{
				c = argument[index2];
				backslash = 2;
			}
			if (argument[index2] == '\\')
			{
				backslash = 1;
				index2++;
				continue;
			}
			if (backslash == 2)
			{
				ft_putchar(c - 100);
				backslash = 0;
				index2++;
				continue;
			}
			ft_putchar(argument[index2]);
			index2++;
		}
		ft_putstr(" ");
		index++;
	}
	if (!no_newline)
		ft_putstr("\n");
	return (1);
}