/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:53:53 by llaurent          #+#    #+#             */
/*   Updated: 2020/03/01 17:25:14 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	len;

	if (n == 0 || dest == src)
		return (dest);
	len = 0;
	if (dest < src)
	{
		while (len < n)
		{
			((char *)dest)[len] = ((char *)src)[len];
			len++;
		}
	}
	else
	{
		len = n;
		while (len > 0)
		{
			len--;
			((char *)dest)[len] = ((char *)src)[len];
		}
	}
	return (dest);
}
