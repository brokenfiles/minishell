#include "includes/minishell.h"

int main(void)
{
	char *bite;
	int i;

	i = 0;
	while (i++ < 100000)
	{
		bite = ft_strnew(50);
		bite[i] = 'X';
	}
}