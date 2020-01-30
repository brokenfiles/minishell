/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:25:15 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/30 19:49:19 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *now;
	t_list *after;

	now = *lst;
	if (lst && *lst)
	{
		while (now)
		{
			if (now->next)
				after = now->next;
			else
				after = NULL;
			(*del)(now->content);
			free(now);
			now = after;
		}
		*lst = NULL;
	}
}
