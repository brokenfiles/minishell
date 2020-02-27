/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:57 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_s(char *buffer, t_arg *arg, int *count, int i)
{
	if (arg->flag != '-')
		padding((arg->flag == '0' ? '0' : ' '), arg->w1 -
		((arg->w2 < i && (arg->w2 > 0 || arg->precision == '.')
		&& arg->w2 >= 0) ? arg->w2 : i), count);
	if (!(arg->precision == '.' && arg->w2 == 0))
		ft_putstr_count(buffer, count, (i < arg->w2 && arg->precision
		== '.') ? i : arg->w2);
	if (arg->flag == '-')
		padding(' ', arg->w1 - ((arg->w2 < i && arg->w2 >= 0 &&
		arg->precision == '.') ? arg->w2 : i), count);
}
