
#include "../../includes/minishell.h"

char	*get_only_export_var(t_data *data, int x)
{
	int i;
	char *new;

	i = 0;
	while (data->arguments[x][i] && ft_isalnum(data->arguments[x][i]))
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
	int i;
	int len;
	char **new_env;

	len = ft_bigstrlen(data->env);
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
	int i;
	char **split;
	char **temp;

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

int		get_export(t_data *data)
{
	int x;
	char *export;

	x = 0;
	while (data->arguments[x])
	{
		if ((export = get_only_export_var(data, x)) != NULL)
		{
			if (remove_quotes(&export) == -1)
				return (0);
			if (!(env_contains(data, export)))
				add_export(data, export);
		}
		x++;
	}
	return (1);
}