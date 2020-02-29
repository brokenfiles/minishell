#include "../../includes/minishell.h"

void	get_last_redirect(t_redirect **link, char *str)
{
	int	x;
	int	i;

	init_int(&x, &i, ft_strlen(str), 1);
	while (x-- >= 0)
	{
		if (str[x] == '>' || str[x] == '<')
		{
			if (x - 1 >= 0 && str[x - 1] == '>' && str[x] == '>')
				(*link)->type = DOUBLE_AQUOTE;
			else if (str[x] == '<')
				(*link)->type = LEFT_AQUOTE;
			else
				(*link)->type = SIMPLE_AQUOTE;
			x += 1;
			break ;
		}
	}
	while (str[x] && is_isspace(str[x]))
		x++;
	while (str[x + i] && !is_separator(str[x + i]))
		i++;
	(*link)->file = ft_substr(str, x, i);
}

char	*frt(char *mem, char *message, char *return_val)
{
	if (mem)
		free(mem);
	if (message)
		ft_putstr_fd(message, 2);
	return (return_val);
}

char	*cut_str(char *tmp, int x, int remove)
{
	char	*join;
	char	*sub;
	char	*dup;
	int		jump;

	sub = ft_substr(tmp, 0, x <= 0 ? 0 : x - remove);
	jump = get_jump(&tmp[x <= 0 ? 0 : x + 1]);
	dup = ft_strdup(&tmp[(x <= 0 ? 0 : x + 1) + jump]);
	join = ft_strjoin(sub, dup);
	free(dup);
	free(sub);
	free(tmp);
	return (join);
}

char	*remove_arrow(char *str)
{
	int		x;
	int		remove;
	char	*tmp;

	init_int(&remove, &x, -1, ft_strlen(str));
	tmp = ft_strdup(str);
	while (x-- >= 0 && str[x])
	{
		if (tmp[x] && (tmp[x] == '>' || tmp[x] == '<'))
		{
			remove++;
			if (x - 1 >= 0 && str[x - 1] == '>')
			{
				remove++;
				if (x - 2 >= 0 && str[x - 2] == '>')
					return (frt(tmp, "minishell: parse error near '>'\n",
							NULL));
			}
			else if (x - 1 >= 0 && str[x - 1] == '<')
				return (frt(tmp, "minishell: parse error near '<'\n", NULL));
			tmp = cut_str(tmp, x, remove);
			break ;
		}
	}
	return (tmp);
}

int		redirection_hub(t_data *data, char **cmds, int pos)
{
	char		*temp;
	t_redirect	*new;
	int			nb;

	nb = get_nb_redirect((*cmds));
	if (nb == 0)
	{
		new = ft_lstnew_redirect();
		ft_lstaddfront_redirect(&data->tpipe[pos].redirect, new);
	}
	while (nb-- > 0)
	{
		new = ft_lstnew_redirect();
		get_last_redirect(&new, (*cmds));
		ft_lstaddfront_redirect(&data->tpipe[pos].redirect, new);
		if ((temp = remove_arrow((*cmds))) == NULL)
		{
			reset_redirections(data);
			return (EXIT_FAILURE);
		}
		free((*cmds));
		(*cmds) = temp;
	}
	return (EXIT_SUCCESS);
}
