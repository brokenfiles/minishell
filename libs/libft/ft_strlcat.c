/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:35:26 by mbrignol          #+#    #+#             */
/*   Updated: 2020/02/24 14:06:19 by mbrignol         ###   ########.fr       */
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
