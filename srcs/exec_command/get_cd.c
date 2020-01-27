
#include "../../includes/minishell.h"

int		get_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		fnr(char **splitted, int code)
{
	int i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (code);
}

int		get_cd(t_data *data)
{
	char **args;

	if (!(args = ft_split(data->arguments, ' ')))
		return (fnr(args, 0));
	if (get_split_len(args) != 1)
		return (fnr(args, 0));
	if (chdir(args[0]) == -1)
	{
		ft_printf("No such file or directory : %s\n", args[0]);
		return (fnr(args, 0));
	}
	return (fnr(args, 1));
}
