
#include "../../includes/minishell.h"

static size_t	count_words(char *s, char c)
{
	size_t	words;
	int		index;
	int		double_quote;
	int		simple_quote;

	index = 0;
	double_quote = 0;
	simple_quote = 0;
	while (s[index] && s[index] == c)
		index++;
	words = (s[index] ? 1 : 0);
	while (s[index])
	{
		if (s[index] == '"')
			double_quote = !double_quote;
		if (s[index] == '\'')
			simple_quote = !simple_quote;
		if (s[index] == c && (!double_quote && !simple_quote) && s[index + 1] && s[index + 1] != c)
			words++;
		index++;
	}
	return (words);
}

char			**ft_split_spec(char const *s, char c)
{
	size_t words;
	int double_quote;
	int simple_quote;
	char *begin;
	char **result;

	if (!s)
		return (NULL);
	double_quote = 0;
	simple_quote = 0;
	words = count_words((char *) s, c);
	if (!(result = (char **) malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	begin = (char *)s;
	while (*s)
	{
		if (*s == '"')
			double_quote = !double_quote;
		if (*s == '\'')
			simple_quote = !simple_quote;
		if (*s == c && (!double_quote && !simple_quote))
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


int parse_arguments(t_data *data)
{
	int		index;

	index = 0;
	data->arguments = ft_split_spec(data->arguments_line, ' ');
	return (1);
}