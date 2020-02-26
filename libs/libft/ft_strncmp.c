/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:01:15 by mbrignol          #+#    #+#             */
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2020/02/26 10:59:25 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	i = 0;
	while (i < n - 1 && s[i] && d[i] && s[i] == d[i])
		i++;
	if (n > 0)
		return (s[i] - d[i]);
	else
		return (0);
}
