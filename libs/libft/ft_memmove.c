/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:21:05 by mbrignol          #+#    #+#             */
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2020/02/26 10:59:25 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
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
