/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:06:14 by mbrignol          #+#    #+#             */
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

void	ft_putnbr(int nb)
{
	int nbr;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nbr = nb * -1;
		write(1, "-", 1);
	}
	else
		nbr = nb;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + 48);
}
