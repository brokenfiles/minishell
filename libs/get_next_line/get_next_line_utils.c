
#include "../../includes/minishell.h"

int		ft_is_line(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}
