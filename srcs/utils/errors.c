
#include "../../includes/minishell.h"

/*
 ** free string split
 */
int		fsp(char **splitted, char *str, int code, char *message)
{
	int i;

	i = 0;
	if (message)
		ft_printf("%s\n", message);
	while (splitted[i])
	{
		if (splitted[i])
			free(splitted[i]);
		i++;
	}
	free(splitted);
	*splitted = NULL;
	free(str);
	str = NULL;
	return (code);
}

int		fnr(void (*f)(void *), void *mem, int code, char *message)
{
	f(mem);
	if (message)
		ft_printf("%s\n", message);
	return (code);
}

int		free_splitted(char **splitted, int code)
{
	int i;

	i = 0;
	while (splitted[i])
	{
		if (splitted[i])
			free(splitted[i]);
		i++;
	}
	free(splitted);
	return (code);
}

int	quit(char *error, int code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit(code);
	return (code);
}