
#include "../../includes/minishell.h"

int		get_cd(t_data *data)
{
	char **args;
	char	*env;

	args = data->arguments;
	if (ft_bigstrlen(args) == 0)
	{
		if ((env = get_env_str(data, "HOME")) == NULL)
			return (0);
		if (chdir(env) == -1)
			return (fnr(free, env, 0, NULL));
		if (!(getcwd(data->cwd, sizeof(data->cwd))))
			return (0);
		free(env);
	}
	if (ft_bigstrlen(args) != 1)
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
