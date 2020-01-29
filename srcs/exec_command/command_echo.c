
#include "../../includes/minishell.h"

static int	ft_nbword(const char *s, char c)
{
	int i;
	int word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	*ft_putstring(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		**ft_split_spec(char const *s, char c)
{
	int		len;
	int		i;
	char	**tab;
	int		quote;

	if (!s)
		return (NULL);
	len = ft_nbword(s, c);
	if (!(tab = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	quote = 0;
	while (*s)
	{
		while (*s && *s == c && quote != 1)
			s++;
		if ((*s && *s != c) || quote == 1)
		{
			if (*s == '"')
				quote++;
			if (quote == 2)
				quote = 1;
			tab[i++] = ft_putstring(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}


int		get_echo(t_data *data)
{
	int		index;
	int		x;
	char	**args;

	index = 0;
	x = 0;
	if (!(args = ft_split(data->arguments, ' ')))
		return (free_splitted(args, 0));
	while (args[index])
	{
		x = 0;
		while (args[index][x])
		{
			if (args[index][x] != '"')
				ft_putchar(args[index][x]);
			x++;
		}
		ft_putchar(' ');
		index++;
	}
//	ft_putstr(data->arguments);
	ft_putstr("\n");
	return (1);
}