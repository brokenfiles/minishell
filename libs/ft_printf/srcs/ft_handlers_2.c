/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:25 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/25 12:31:25 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_puthexa_buff(char **buffer, long int nb, t_arg *arg, int flag)
{
	unsigned long int	a;
	char				*base;

	base = (arg->conv == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (arg->flag == '#' || arg->conv == 'p')
	{
		ft_putstr_buff(buffer, "0x");
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
