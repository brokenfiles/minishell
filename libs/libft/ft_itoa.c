/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:53:13 by llaurent          #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_itoamalloc(int nb)
{
	int xd;

	xd = 0;
	xd = (nb <= 0 ? 1 : 0);
	while (nb != 0)
	{
		nb = nb / 10;
		xd++;
	}
	return (xd);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				less;
	unsigned int	nb;

	str = NULL;
	less = (n < 0 ? 1 : 0);
	len = ft_itoamalloc(n);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	nb = (n < 0 ? -n : n);
	while (len >= 0)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	if (less == 1)
		str[0] = '-';
	return (str);
}
