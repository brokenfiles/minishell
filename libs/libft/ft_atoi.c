/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:17:47 by mbrignol          #+#    #+#             */
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

int	ft_atoi(const char *nptr)
{
	unsigned int		i;
	unsigned long int	nb;
	unsigned long int	less;

	less = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' ||
			nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			less = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + (unsigned long int)(nptr[i++] - 48);
	if (nb > 9223372036854775807 && less == (unsigned long int)-1)
		return (0);
	else if (nb > 9223372036854775807)
		return (-1);
	return (nb * less);
}
