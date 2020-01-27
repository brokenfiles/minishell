/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:57 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/26 10:49:08 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_s(char *buffer, t_arg *arg, int *count, int i)
{
	if (arg->width1 < 0)
	{
		arg->flag = '-';
		arg->width1 = -arg->width1;
	}
	if (arg->flag != '-')
		padding(' ', arg->width1 - ((arg->width2 < i &&
		(arg->width2 > 0 || arg->precision == '.')) ?
		arg->width2 : i), count);
	if (!(arg->precision == '.' && arg->width2 == 0))
		ft_putstr_count(buffer, count, (i < arg->width2 && arg->precision
		== '.') ? i : arg->width2);
	if (arg->flag == '-')
		padding(' ', arg->width1 - ((arg->width2 < i && arg->width2 >= 0 &&
		arg->precision == '.') ? arg->width2 : i), count);
}
