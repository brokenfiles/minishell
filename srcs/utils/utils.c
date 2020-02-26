#include "../../includes/minishell.h"

void	init_int(int *int1, int *int2, int val1, int val2)
{
	if (int1)
		*int1 = val1;
	if (int2)
		*int2 = val2;
}