/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:19 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/26 13:30:01 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_u(char *buffer, t_arg *arg, int *count, int i)
{
	if (arg->width1 < 0)
	{
		arg->width1 = -arg->width1;
		arg->flag = '-';
	}
	if (arg->flag != '-' && arg->width1 && ((arg->width2 >= 0 && arg->flag ==
	'0' && arg->precision == '.') || arg->flag != '0'))
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 : i),
				count);
	if (arg->flag != '-' && !arg->width2 &&
		((arg->width2 < i && arg->width2) || (arg->width2 == 0 &&
		arg->flag == '0' && arg->precision != '.')))
		padding('0', arg->width1 - ((arg->width2 > i) ? arg->width2 : i),
				count);
	else if (arg->width2 > 0)
		padding('0', arg->width2 - i, count);
	if (!(buffer[0] == '0' && arg->precision == '.'))
		ft_putstr_count(buffer, count, 0);
	else if (arg->precision == '.' && arg->width1)
		ft_putchar_count((arg->width2 > 0 ? '0' : ' '), count);
	else
		i--;
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - ((arg->width2 > i) ? arg->width2 : i),
				count);
}

void	priv_fct_1(int *neg, char **buffer, t_arg *arg, int *i)
{
	if (*buffer[0] == '-')
	{
		(*buffer)++;
		if (((arg->precision == '.' && arg->width2 >= *i) ||
		(arg->width2 < *i && (arg->width1 > 0 && arg->flag == '-'))))
			(*i)--;
		*neg = 1;
	}
	if (arg->width1 < 0)
	{
		arg->width1 = -arg->width1;
		arg->flag = '-';
	}
}

int		priv_fct_3(t_arg *arg, int i)
{
	return (arg->flag != '-' && !arg->width2 &&
			((arg->width2 < i && arg->width2) || (arg->width2 == 0 &&
			arg->flag == '0'))
			&& !(!arg->width2 && arg->precision == '.' && arg->flag == '0'));
}

int		priv_fct_4(t_arg *arg)
{
	return (arg->flag != '-' && arg->width1 > 0 &&
			(((arg->width2 > 0 && arg->flag == '0') || arg->flag != '0') ||
			(!arg->width2 && arg->precision == '.' && arg->flag == '0')));
}

void	handle_di(char *buffer, t_arg *arg, int *count, int i)
{
	int neg;

	neg = 0;
	priv_fct_1(&neg, &buffer, arg, &i);
	if (priv_fct_4(arg))
		padding(' ', arg->width1 -
		((arg->width2 > i) ? arg->width2 + neg : i), count);
	if (neg == 1)
		ft_putchar_count('-', count);
	if (priv_fct_3(arg, i))
		padding('0', arg->width1 - ((arg->width2 > i) ? arg->width2 : i),
				count);
	else if (arg->width2 > 0)
		padding('0', arg->width2 - i, count);
	if (!(buffer[0] == '0' && arg->precision == '.'))
		ft_putstr_count(buffer, count, 0);
	else if ((arg->width2 && arg->precision == '.') ||
	(!arg->width2 && arg->precision == '.' && arg->flag == 0 && arg->width1))
		ft_putchar_count(arg->width2 != 0 ? '0' : ' ', count);
	else
		i--;
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 -
		((arg->width2 > i) ? arg->width2 + neg : i + neg), count);
}
