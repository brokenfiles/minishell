#include "../../includes/minishell.h"

int	handle_right_arrow(t_redirect *begin)
{
	t_redirect	*current;
	int			fd;

	while (begin)
	{
		if (begin->type == DOUBLE_AQUOTE || begin->type == SIMPLE_AQUOTE)
		{
			current = begin;
			fd = open(current->file, O_CREAT, 0644);
			close(fd);
		}
		begin = begin->next;
	}
	fd = redirect_output(current);
	return (fd);
}

int		is_right_arrow(t_redirect *beggin)
{
	while (beggin)
	{
		if (beggin->type == SIMPLE_AQUOTE || beggin->type == DOUBLE_AQUOTE)
			return (1);
		else if (beggin->type == LEFT_AQUOTE)
			return (0);
		beggin = beggin->next;
	}
	return (0);
}

int		is_left_arrow(t_redirect *beggin)
{
	while (beggin)
	{
		if (beggin->type == LEFT_AQUOTE)
			return (1);
		beggin = beggin->next;
	}
	return (0);
}

t_redirect		*got_right_after_left_arrow(t_redirect *save)
{
	t_redirect *to_redirect;

	to_redirect = NULL;
	while (save)
	{
		if (save->type == SIMPLE_AQUOTE || save->type == DOUBLE_AQUOTE)
			to_redirect = save;
		save = save->next;
	}
	if (to_redirect == NULL)
		return (NULL);
	else
		return (to_redirect);
}

int	handle_left_arrow(t_redirect *begin)
{
	int fd;
	int save;
	t_redirect *current;
	t_redirect *first_link;

	first_link = begin;
	while (begin)
	{
		if (begin->type == LEFT_AQUOTE)
			current = begin;
		begin = begin->next;
	}
	if ((fd = open(current->file, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	save = dup(STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close (fd);
	dup2(STDIN_FILENO, save);
	close(save);
	if (got_right_after_left_arrow(first_link))
		handle_right_arrow(first_link);
	return (EXIT_SUCCESS);
}
