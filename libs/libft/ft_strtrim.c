/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:13:12 by mbrignol          #+#    #+#             */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		lens1;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && ft_strchr((char *)set, (char)s1[i]) != NULL)
		i++;
	lens1 = ft_strlen((char *)&s1[i]);
	if (lens1 != 0)
	{
		while (ft_strchr((char *)set, (char)s1[i + lens1 - 1]) != NULL)
			lens1--;
	}
	if (!(str = malloc(sizeof(char) * (lens1 + 1))))
		return (NULL);
	ft_strlcpy(str, &s1[i], lens1 + 1);
	str[lens1] = '\0';
	return (str);
}
