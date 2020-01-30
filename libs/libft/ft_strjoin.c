/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:17:14 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/30 14:52:45 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	if (!(join = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(join, s1, size);
	ft_strlcat(join, s2, size);
	return (join);
}
