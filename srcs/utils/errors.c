
#include "../../includes/minishell.h"

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

void	error_command_nf(char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}
