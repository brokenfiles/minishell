#include "../../includes/minishell.h"

int	get_next_char(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (str[index] == c)
		return (index);
	return (-1);
}

int	get_last_char(char *str, char c)
{
	int	index;
	int	last_char;

	last_char = -1;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			last_char = index;
		index++;
	}
	if (str[index] == c)
		last_char = index;
	return (last_char);
}