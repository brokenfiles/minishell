
#include "../../includes/minishell.h"

int		is_in_env(t_data *data, char *env_line)
{
	int	index;

<<<<<<< HEAD
	x = 0;
	if (!(str = malloc(sizeof(char*) * (tabsize(data->env)))))
<<<<<<< HEAD
		return (0);
	j = 0;
	while (x < i)
	{
		str[x] = ft_strdup(data->env[j]);
		x++;
		j++;
	}
	j++;
	while (data->env[j])
	{
		str[x] = ft_strdup(data->env[j]);
		x++;
		j++;
	}
	str[x] = 0;
	free_splitted(data->env, 0);
	data->env = str;
	return (1);
=======
=======
	index = 0;
	while (data->env[index])
	{
		if (ft_strcmp(data->env[index], env_line) == 0 &&
		ft_strlen(data->env[index]) == ft_strlen(env_line))
			return (1);
		index++;
	}
	return (0);
}

int		remove_env(t_data *data, char *env_line)
{
	char	**new_env;
	int		index;
	int		index2;
	char	*tmp;

	index = 0;
	index2 = 0;
	if (!(new_env = malloc(sizeof(char *) * tabsize(data->env) +
			1 + (is_in_env(data, env_line) ? -1 : 0))))
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
		return (EXIT_FAILURE);
	while (data->env[index])
	{
		if (!(tmp = ft_substr(data->env[index], 0,
				get_first_char(data->env[index], '='))))
			return (EXIT_FAILURE);
		if (ft_strcmp(tmp, env_line))
			new_env[index2++] = ft_strdup(data->env[index]);
		free(tmp);
		index++;
	}
	new_env[index2] = NULL;
	free_splitted(data->env, 0);
	data->env = new_env;
	return (EXIT_SUCCESS);
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
}

int		exec_unset(t_data *data, char **cmds)
{
<<<<<<< HEAD
<<<<<<< HEAD
	int		i;
	int		index;
	char	**split;

	index = 0;
	i = 0;
	data->arguments = cmds + 1;
	if (tabsize(data->arguments) < 1)
		return (EXIT_FAILURE);
	while (tabsize(data->env) > i && data->env[i])
	{
		split = ft_split(data->env[i], '=');
		if (ft_strcmp(split[0], data->arguments[index]) == 0)
		{
			if (ft_strlen(split[0]) == ft_strlen(data->arguments[index]))
			{
				get_unset_tab(data, i);
				if (data->arguments[index + 1])
				{
					free_splitted(split, 0);
					i = 0;
					index++;
					continue;
				}
			}
		}
		free_splitted(split, 0);
		i++;
		if (i >= tabsize(data->env) && data->arguments[index + 1])
		{
			i = 0;
			index++;
		}
=======
	int		index[2];
	char	**split;
=======
	int		index;
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799

	index = 0;
	data->arguments = cmds + 1;
	if (tabsize(data->arguments) < 1)
		return (EXIT_SUCCESS);
	while (data->arguments[index])
	{
		if (remove_env(data, data->arguments[index]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
<<<<<<< HEAD
		if (ft_strcmp(split[0], data->arguments[index[1]]) == 0 &&
			ft_strlen(split[0]) == ft_strlen(data->arguments[index[1]]))
		{
			if ((get_unset_tab(data, index[0])) == EXIT_FAILURE)
				return (free_splitted(split, EXIT_FAILURE));
			if (data->arguments[index[1] + 1])
			{
				free_splitted(split, 0);
				init_int(&index[0], &index[1], 0, index[1] + 1);
				continue;
			}
		}
		free_splitted(split, 0);
		index[0]++;
		if (index[0] >= tabsize(data->env) && data->arguments[index[1] + 1])
			init_int(&index[0], &index[1], 0, index[1] + 1);
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
=======
		index++;
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
	}
	return (EXIT_SUCCESS);
}
