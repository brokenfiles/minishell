
#include "../../includes/minishell.h"

int		handle_no_argument(char **args, t_data *data)
{
	char	*env;

	if (tabsize(args) == 0 || (tabsize(args) == 1 && ft_strlen(args[0]) > 0
	&& args[0][0] == '~'))
	{
		if ((env = get_env(data, "HOME")) == NULL)
			return (EXIT_FAILURE);
		if (chdir(env) == -1)
			return (fnr(free, env, EXIT_FAILURE, NULL));
		if (!(getcwd(data->cwd, sizeof(data->cwd))))
			return (EXIT_FAILURE);
		free(env);
		return (2);
	}
	return (EXIT_SUCCESS);
}

int		exec_cd(t_data *data, char **cmds)
{
	char	**args;

	args = cmds + 1;
	if (handle_no_argument(args, data) == 2)
		return (EXIT_SUCCESS);
	if (tabsize(args) > 1)
	{
		ft_printf("cd: too many arguments\n");
		return (EXIT_FAILURE);
	}
	if (chdir((const char *)args[0]) == -1)
	{
		ft_printf("cd: no such file or directory: %s\n", args[0]);
		return (EXIT_FAILURE);
	}
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
