
#include "../../includes/minishell.h"

char	*get_only_export_var(t_data *data, int x)
{
	int		i;
	char	*new;

	i = 0;
	while (data->arguments[x][i] && (ft_isalnum(data->arguments[x][i]) ||
	data->arguments[x][i] == '_'))
		i++;
	if (i > 0 && data->arguments[x][i] && data->arguments[x][i] == '=')
		i++;
	else
		return (NULL);
	while (data->arguments[x][i] && ft_isprint(data->arguments[x][i]))
		i++;
	if (!(new = ft_substr(data->arguments[x], 0, i)))
		return (NULL);
	return (new);
}

int		add_export(t_data *data, char *export)
{
	int		i;
	int		len;
	char	**new_env;

	len = tabsize(data->env);
	i = 0;
	if (!(new_env = malloc(sizeof(char*) * (len + 2))))
		return (0);
	while (data->env[i])
	{
		new_env[i] = ft_strdup(data->env[i]);
		i++;
	}
	new_env[i++] = export;
	new_env[i] = 0;
	free_splitted(data->env, 0);
	data->env = new_env;
	return (1);
}

int		env_contains(t_data *data, char *str)
{
	int		i;
	char	**split;
	char	**temp;

	i = 0;
	temp = ft_split(str, '=');
	while (data->env[i])
	{
		split = ft_split(data->env[i], '=');
		if (ft_strcmp(split[0], temp[0]) == 0)
		{
			if (ft_strlen(split[0]) == ft_strlen(temp[0]))
			{
				free(data->env[i]);
				data->env[i] = str;
				free_splitted(temp, 0);
				return (free_splitted(split, 1));
			}
		}
		free_splitted(split, 0);
		i++;
	}
	return (free_splitted(temp, 0));
}

int		sort_env_export(t_data *data)
{
	int		index;
	char	**temp;

	if (!(temp = malloc(sizeof(char*) * (tabsize(data->env) + 1))))
		return (EXIT_FAILURE);
	temp[tabsize(data->env)] = 0;
	index = 0;
	while (index++ < tabsize(data->env))
		temp[index - 1] = ft_strdup(data->env[index - 1]);
	index = 0;
	while (temp[index] && temp[index + 1])
	{
		if (ft_strcmp(temp[index], temp[index + 1]) > 0)
		{
			ft_swap((void **)&temp[index], (void **)&temp[index + 1]);
			index = 0;
		}
		else
			index++;
	}
	index = 0;
	while (index < tabsize(temp) && temp[index])
		ft_printf("%s\n", temp[index++]);
	return (free_splitted(temp, EXIT_SUCCESS));
}

int		exec_export(t_data *data, char **cmds)
{
	int		x;
	char	*export;

	data->arguments = cmds + 1;
	x = 0;
	while (data->arguments[x])
	{
		if ((export = get_only_export_var(data, x)) != NULL)
		{
			if (remove_quotes(&export) == -1)
				return (EXIT_FAILURE);
			if (!(env_contains(data, export)))
				add_export(data, export);
		}
		x++;
	}
	if (x == 0)
		sort_env_export(data);
	return (EXIT_SUCCESS);
}
