/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:07:13 by mbrignol          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2020/02/26 10:59:25 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
=======
/*   Updated: 2020/02/26 17:33:24 by llaurent         ###   ########.fr       */

>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
