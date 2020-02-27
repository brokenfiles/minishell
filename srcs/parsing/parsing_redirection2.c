#include "../../includes/minishell.h"

int	get_nb_redirect(char *str)
{
	int	index;
	int	nb;

	nb = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] && (str[index] == '<' || str[index] == '>'))
		{
			nb++;
			while (str[index] && (str[index] == '<' || str[index] == '>'))
				index++;
		}
		else
			index++;
	}
	return (nb);
}
