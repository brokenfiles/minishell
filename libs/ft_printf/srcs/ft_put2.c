/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:52:39 by jchotel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
brignol         ###   ########.fr       */
=======
/*   Updated: 2020/02/26 10:59:26 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7:libs/ft_printf/srcs/ft_put2.c
=======
/*   Updated: 2020/02/26 17:33:24 by llaurent         ###   ########.fr       */
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_puthexa_buff(char **buffer, long int nb, t_arg *arg, int flag)
{
	unsigned long int	a;
	char				*base;

	base = (arg->conv == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (arg->conv == 'p')
	{
		arg->conv = (arg->conv == 'p') ? 'P' : arg->conv;
	}
	a = (nb < 0) ? -(nb + 1) : nb;
	(nb < 0) ? ft_strjoin_c(buffer, '-') : 0;
	flag = (nb < 0) ? 1 : flag;
	(a >= 16) ? ft_puthexa_buff(buffer, (long int)(a / 16), arg, flag) : 0;
	ft_strjoin_c(buffer, base[(flag == 1) ? (15 - a % 16) : (a % 16)]);
}

void	ft_putoctal_buff(char **buffer, int nb)
{
	unsigned int	a;
	char			*base;

	base = "01234567";
	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_strjoin_c(buffer, '-') : 0;
	(a >= 8) ? ft_strjoin_c(buffer, (int)(a / 8)) : 0;
	ft_strjoin_c(buffer, base[a % 8]);
}
