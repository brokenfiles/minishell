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

t_redirect		*hello_can_you_tell_me_if_it_has_a_right_arrow_after_left_arrow_thanks(t_redirect *save)
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

int	handle_left_arrow(t_data *data, t_redirect *begin, int is_pipeline)
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
	save = dup(STDIN_FILENO);
	if (!(fd = open(current->file, O_RDONLY)))
		return (0);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (0);
	close (fd);
	dup2(STDIN_FILENO, save);
	close(save);
	if (hello_can_you_tell_me_if_it_has_a_right_arrow_after_left_arrow_thanks(first_link) != NULL)
		handle_right_arrow(first_link);
	else if (is_pipeline == 1)
		redirect(data->pipe[1], 1);
	return (1);
}
