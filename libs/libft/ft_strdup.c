/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:55:26 by llaurent          #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*temp;
	char	*dup;
	int		i;

	i = 0;
	temp = (char*)s;
	len = ft_strlen(temp);
	if (!(dup = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		dup[i] = temp[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
