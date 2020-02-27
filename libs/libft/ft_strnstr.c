/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:55:50 by llaurent          #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	y;
	char			*s;
	char			*d;

	i = 0;
	s = (char*)s1;
	d = (char*)s2;
	if (ft_strlen(d) == 0)
		return (s);
	if (ft_strlen(s) == 0)
		return (NULL);
	while (s[i] && i < n)
	{
		y = 0;
		while (d[y] == s[i + y] && i + y < n)
		{
			y++;
			if (d[y] == '\0')
				return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
