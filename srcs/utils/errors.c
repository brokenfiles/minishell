
#include "../../includes/minishell.h"

int		fnr(char **splitted, int code)
{
	int i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	*splitted = NULL;
	return (code);
}

int	quit(char *error, int code)
{
	printf("minishell: %s\n", error);
	exit(code);
	return (code);
}