/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:52:52 by llaurent          #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
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
