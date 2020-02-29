#include "../../includes/minishell.h"

int		get_first_char(char *str, char c)
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
	return (0);
}

void	init_int(int *int1, int *int2, int val1, int val2)
{
	if (int1)
		*int1 = val1;
	if (int2)
		*int2 = val2;
}
