/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:53:16 by llaurent          #+#    #+#             */
/*   Updated: 2020/03/01 17:25:14 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = NULL;
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			temp = ft_lstlast(*alst);
			new->next = NULL;
			temp->next = new;
		}
	}
}
