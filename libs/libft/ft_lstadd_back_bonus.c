/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:59:34 by mbrignol          #+#    #+#             */
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2020/02/26 10:59:25 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
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
