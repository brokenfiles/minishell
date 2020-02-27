
#include "../../includes/minishell.h"

int		count_words(char *s, char c)
{
	int		words;
	int		index;
	int		double_quote;
	int		simple_quote;

	if (!s)
		return (-1);
	index = 0;
	double_quote = 0;
	simple_quote = 0;
	while (s[index] && s[index] == c)
		index++;
	words = (s[index] ? 1 : 0);
	while (s[index])
	{
		if (s[index] == '"' && !simple_quote)
			double_quote = !double_quote;
		if (s[index] == '\'' && !double_quote)
			simple_quote = !simple_quote;
		if (s[index] == c && (!double_quote && !simple_quote) &&
		s[index + 1] && s[index + 1] != c)
			words++;
		index++;
	}
	return (words);
}

void	define_quotes(int *sq, int *dq, char c)
{
	if (c == '"' && !(*sq))
		*dq = !(*dq);
	if (c == '\'' && !(*dq))
		*sq = !(*sq);
}

char	**ft_split_spec(char const *s, char c)
{
	int		words;
	int		indexes[2];
	char	*begin;
	char	**result;

	init_int(&indexes[0], &indexes[1], 0, 0);
	words = count_words((char *)s, c);
	if ((words == -1) || !(result = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	begin = (char *)s;
	while (*s)
	{
		define_quotes(&indexes[0], &indexes[1], *s);
		if (*s == c && (!indexes[1] && !indexes[0]))
		{
			if (begin != s)
				*(result++) = ft_substr(begin, 0, s - begin);
			begin = (char *)s + 1;
		}
		++s;
	}
	if (begin != s)
		*(result++) = ft_substr(begin, 0, s - begin);
	*result = NULL;
	return (result - words);
}
