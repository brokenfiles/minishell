
#include "../../includes/minishell.h"

int	quit(char *error, int code)
{
	printf("%s\n", error);
	exit(code);
	return (code);
}