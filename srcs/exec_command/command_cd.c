
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
	char **args;
	char	*env;

	args = data->arguments;
	if (get_split_len(args) == 0)
	{
		if ((env = get_env_str(data, "HOME")) == NULL)
		{
			ft_printf("$HOME variable does not exists.\n");
			return (0);
		}
		if (chdir(env) == -1)
		{
			ft_printf("No such file or directory : %s\n", env);
			free(env);
			return (0);
		}
		if (!(getcwd(data->cwd, sizeof(data->cwd))))
			return (0);
		free(env);
	}
	if (get_split_len(args) != 1)
		return (0);
	if (chdir(args[0]) == -1)
	{
		ft_printf("No such file or directory : %s\n", args[0]);
		return (0);
	}
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (0);
	return (1);
}
