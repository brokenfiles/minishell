/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:19 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/24 14:06:19 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	padding_space(t_arg *arg, int i, int sign, int *count)
{
	if (sign == 2 && !arg->w2 && arg->precision == '.')
	{
		sign = -1;
	}
	else if (arg->w2 && arg->precision == '.'
	&& (arg->pos || sign == 1) && arg->w2 > i)
		sign = 1;
	else
		sign = 0;
	if (arg->flag != '-' && arg->w1 > 0 &&
		(((arg->w2 > 0 && arg->flag == '0') || arg->flag != '0') ||
		(!arg->w2 && arg->precision == '.' && arg->flag == '0')))
	{
		padding(' ', arg->w1 -
		((arg->w2 > i) ? arg->w2 + sign : i + sign), count);
	}
}

void	padding_0(t_arg *arg, int i, int *count)
{
	if (arg->flag != '-' && !arg->w2 && ((arg->w2 < i && arg->w2)
	|| (arg->w2 == 0 && arg->flag == '0'))
		&& !(!arg->w2 && arg->precision == '.' && arg->flag == '0'))
	{
		padding('0', arg->w1 - ((arg->w2 > i) ? arg->w2 : i),
				count);
	}
	else if (arg->w2 > 0)
		padding('0', arg->w2 - i, count);
}

void	handle_u(char *buffer, t_arg *arg, int *count, int i)
{
	padding_space(arg, i, 0, count);
	padding_0(arg, i, count);
	if (!(buffer[0] == '0' && arg->precision == '.' && !arg->w2))
		ft_putstr_count(buffer, count, 0);
	else if (arg->precision == '.' && arg->w1)
		ft_putchar_count((arg->w2 > 0 ? '0' : ' '), count);
	else
		i--;
	if (arg->w1 && arg->flag == '-')
		padding(' ', arg->w1 - ((arg->w2 > i) ? arg->w2 : i),
				count);
}

void	negative_nb(int *neg, char **buffer, t_arg *arg, int *i)
{
	if (*buffer[0] == '-')
	{
		(*buffer)++;
		if ((arg->precision == '.' && arg->w2 >= *i) ||
		(arg->w2 < *i && (arg->w1 > 0 && arg->flag == '-')))
			(*i)--;
		*neg = 1;
	}
	else if (arg->pos)
	{
		if (((arg->w1 && !arg->w2) ||
		arg->w2 < *i) && arg->flag != '-')
			(*i)++;
		*neg = 2;
	}
}

void	handle_di(char *buffer, t_arg *arg, int *count, int i)
{
	int neg;

	neg = 0;
	negative_nb(&neg, &buffer, arg, &i);
	padding_space(arg, i, neg, count);
	if (neg == 1)
		ft_putchar_count('-', count);
	else if (neg == 2)
		ft_putchar_count(arg->pos, count);
	padding_0(arg, i, count);
	if (!(buffer[0] == '0' && arg->precision == '.'))
		ft_putstr_count(buffer, count, 0);
	else if (arg->precision == '.' && (arg->w2 || (!arg->w2
	&& arg->w1 && arg->pos != '+')))
		ft_putchar_count(arg->w2 != 0 ? '0' : ' ', count);
	else
		i--;
	if (neg > 0)
		neg = 1;
	if (arg->w1 && arg->flag == '-')
		padding(' ', arg->w1 -
		((arg->w2 > i) ? arg->w2 + neg : i + neg), count);
}
