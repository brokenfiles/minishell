/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:18:08 by mbrignol          #+#    #+#             */
/*   Updated: 2020/02/14 22:18:44 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*now;

	now = lst;
	i = 0;
	while (now != NULL)
	{
		now = now->next;
		i++;
	}
	return (i);
}
