
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

//SI DEJA PRESENT REMPLACER
//TRIM GUILLEMET

int		get_export(t_data *data)
{
	int x;
	char *export;

	x = 0;
	while (data->arguments[x])
	{
		if ((export = get_only_export_var(data, x)) != NULL)
			add_export(data, export);
		x++;
	}
	return (1);
}