/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:46:11 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/27 18:10:46 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	*src;

	src = (unsigned char*)s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == a)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
