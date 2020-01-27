
#include "../../includes/minishell.h"

int		get_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		check_args_cd(char *arg, char **str)
{
	int i;

	i = 0;
	while (arg[i] && !(arg[i] == ' ' || arg[i] == ';' || arg[i] == '|'))
		i++;

	*str = ft_substr(arg, 0, i);
	printf("%s\n", *str);
	return (1);
}

int		get_cd(t_data *data)
{
//	char	**arguments;
//
//	arguments = ft_split(data->arguments, ' ');
//	if (get_split_len(arguments) != 1)
//		return (0);
	char *str;

	check_args_cd(data->arguments, &str);

	if (chdir("..") == -1)
	{
		printf("KOOOOO");
		return (0);
	}
	return (1);
}
