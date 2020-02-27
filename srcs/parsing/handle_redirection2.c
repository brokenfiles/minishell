#include "../../includes/minishell.h"

t_redirect	*has_only_reg(t_redirect *begin)
{
	struct stat	buff;
	t_redirect	*current;
	int			ret;

	current = NULL;
	while (begin)
	{
		if (begin->type == LEFT_AQUOTE)
		{
			current = begin;
			ret = stat(current->file, &buff);
			if (ret == -1 || !S_ISREG(buff.st_mode))
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(current->file, 2);
				ft_putstr_fd(": No such file or directory\n", 2);
				return (NULL);
			}
		}
		begin = begin->next;
	}
	return (current);
}
