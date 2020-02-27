#include "../../includes/minishell.h"

int			handle_right_arrow(t_redirect *begin)
{
	t_redirect	*current;
	int			fd;

	while (begin)
	{
		if (begin->type == DOUBLE_AQUOTE || begin->type == SIMPLE_AQUOTE)
		{
			current = begin;
			fd = open(current->file, begin->type == DOUBLE_AQUOTE ?
			O_CREAT : O_CREAT | O_TRUNC, 0644);
			close(fd);
		}
		begin = begin->next;
	}
	fd = redirect_output(current);
	return (fd);
}

int			is_right_arrow(t_redirect *begin)
{
	while (begin)
	{
		if (begin->type == SIMPLE_AQUOTE || begin->type == DOUBLE_AQUOTE)
			return (1);
		else if (begin->type == LEFT_AQUOTE)
			return (0);
		begin = begin->next;
	}
	return (0);
}

int			is_left_arrow(t_redirect *begin)
{
	while (begin)
	{
		if (begin->type == LEFT_AQUOTE)
			return (1);
		begin = begin->next;
	}
	return (0);
}

t_redirect	*got_right_after_left_arrow(t_redirect *save)
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

int			handle_left_arrow(t_data *data, t_redirect *begin, int is_pipeline)
{
	int			fd;
	int			save;
	t_redirect	*current;

	if (!(current = has_only_reg(begin)))
		return (EXIT_FAILURE);
	if ((fd = open(current->file, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	save = dup(STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(fd);
	dup2(STDIN_FILENO, save);
	close(save);
	if (got_right_after_left_arrow(begin))
		handle_right_arrow(begin);
	else if (is_pipeline == 1)
		redirect(data->pipe[1], 1);
	return (EXIT_SUCCESS);
}
