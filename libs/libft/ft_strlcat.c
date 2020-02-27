/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:55:31 by llaurent          #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t count)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < count && dst[j])
		j++;
	i = j;
	while (j + 1 < count && src[j - i])
	{
		dst[j] = src[j - i];
		j++;
	}
	if (i < count)
		dst[j] = '\0';
	return (i + ft_strlen((char*)src));
}
