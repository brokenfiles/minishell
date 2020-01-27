
#include "../../includes/minishell.h"

int		get_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		get_cd(t_data *data)
{
	char	**arguments;

	arguments = ft_split(data->arguments, ' ');
	if (get_split_len(arguments) != 1)
	{
		ft_putstr("too many arguments.\n");
		return (0);
	}
	if (chdir(arguments[0]) == -1)
	{
		ft_putstr("this directory does not exists.\n");
		return (0);
	}
	return (1);
}
