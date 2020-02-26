
#include "../../includes/minishell.h"

<<<<<<< HEAD
int		exec_echo(t_data *data, char **cmds)
{
	(void)data;
=======
int		exec_echo(char **cmds)
{
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	int	x;
	int	is_n;
	int	len;

	is_n = 0;
	x = 1;
<<<<<<< HEAD

	if ((len = tabsize(cmds)) >= 2 && ft_strcmp(cmds[1], "-n") == 0)
		is_n = 1;

=======
	if ((len = tabsize(cmds)) >= 2 && ft_strcmp(cmds[1], "-n") == 0)
		is_n = 1;
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
	if (is_n)
		x++;
	while (cmds[x])
		len - 1 != x ? ft_printf("%s ", cmds[x++]) : ft_printf("%s", cmds[x++]);
	if (!is_n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
