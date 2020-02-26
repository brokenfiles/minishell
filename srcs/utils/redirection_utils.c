#include "../../includes/minishell.h"

t_redirect	*ft_lstlast_redirect(t_redirect *lst)
{
	t_redirect *now;

	if (!lst)
		return (NULL);
	now = lst;
	while (now->next != NULL)
	{
		now = now->next;
	}
	return (now);
}

void	ft_lstaddback_redirect(t_redirect **alst, t_redirect *new)
{
	t_redirect *temp;

	temp = NULL;
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			temp = ft_lstlast_redirect(*alst);
			new->next = NULL;
			new->file = NULL;
			temp->next = new;
		}
	}
}

t_redirect	*ft_lstnew_redirect(void)
{
	t_redirect *new;

	if (!(new = (t_redirect*)malloc(sizeof(t_redirect))))
		return (NULL);
	new->next = NULL;
	new->file = NULL;
	new->type = -1;
	return (new);
}

void	ft_lstclear_redirect(t_redirect **lst, void (*del)(void*))
{
	t_redirect *now;
	t_redirect *after;

	now = *lst;
	(void)(*del);
	if (lst && *lst)
	{
		while (now)
		{
			if (now->next)
				after = now->next;
			else
				after = NULL;
			if (now->file != NULL)
				(*del)(now->file);
			now->file = NULL;
			free(now);
			now = after;
		}
		*lst = NULL;
	}
}

void	ft_lstaddfront_redirect(t_redirect **alst, t_redirect *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
