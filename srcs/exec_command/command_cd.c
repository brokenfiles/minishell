
#include "../../includes/minishell.h"

<<<<<<< HEAD
int		exec_cd(t_data *data, char **cmds)
{
	char **args;
	char	*env;

	args = cmds + 1;
	if (tabsize(args) == 0 || (tabsize(args) == 1 && ft_strlen(args[0]) > 0 && args[0][0] == '~'))
	{
		if ((env = get_env_str(data, "HOME")) == NULL)
			return (EXIT_FAILURE);
		if (chdir(env) == -1)
			return (fnr(free, env, 1, NULL));
		if (!(getcwd(data->cwd, sizeof(data->cwd))))
			return (EXIT_FAILURE);
		free(env);
		return (EXIT_SUCCESS);
	}
=======
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
			return (fnr(free, env, EXIT_FAILURE, NULL));
		free(env);
		return (2);
	}
	return (EXIT_SUCCESS);
}

int		exec_cd(t_data *data, char **cmds)
{
	char	**args;
	int		ret;

	args = cmds + 1;
<<<<<<< HEAD
	if (handle_no_argument(args, data) == 2)
		return (EXIT_SUCCESS);
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
=======
	ret = handle_no_argument(args, data);
	if (ret != EXIT_SUCCESS)
		return (ret == 2 ? EXIT_SUCCESS : EXIT_FAILURE);
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
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
