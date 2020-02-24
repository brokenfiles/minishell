/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:32:01 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/24 14:06:19 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	reset_arg(t_arg *arg)
{
	arg->conv = 0;
	arg->flag = 0;
	arg->precision = 0;
	arg->modi = 0;
	arg->w1 = 0;
	arg->w2 = 0;
	arg->flag_s = 0;
	arg->pos = 0;
}

void	handle_precision(char *handler, t_arg *arg, va_list va)
{
	if (*handler == '*' && arg->w1 == 0 &&
		!arg->flag_s && arg->precision != '.')
	{
		arg->w1 = va_arg(va, int);
		if (arg->w1 < 0)
		{
			arg->flag = '-';
			arg->w1 = -arg->w1;
		}
		arg->flag_s = 1;
	}
	else if (*handler == '*' && !arg->w2)
		arg->w2 = va_arg(va, int);
	else
		arg->precision = '.';
}

int		set_arg(t_arg *arg, char *handler, va_list va)
{
	if (ft_strchr("+ #", *handler) && !arg->w1 && !arg->w2 && !arg->conv)
		arg->pos = *handler;
	else if (ft_strchr("0-", *handler) &&
		(!arg->flag || (arg->flag != '-' && *handler == '-')) &&
		!arg->w1 && !arg->w2 && !arg->conv)
		arg->flag = *handler;
	else if (ft_isdigit(*handler) && !arg->w1 && !arg->precision &&
		!arg->conv && !arg->w2 && !arg->modi)
		arg->w1 = atoi((const char *)handler);
	else if (ft_isdigit(*handler) && !arg->precision && !arg->conv)
		return (1);
	else if (ft_strchr(".*", *handler) && !arg->conv)
		handle_precision(handler, arg, va);
	else if (ft_isdigit(*handler) && !arg->w2 && !arg->modi && !arg->conv)
		arg->w2 = atoi((const char *)handler);
	else if (ft_isdigit(*handler) && !arg->modi && !arg->conv)
		return (1);
	else if (ft_strchr("hl", *handler) &&
		(!arg->modi || arg->modi == 'h' || arg->modi == 'l') && !arg->conv)
		arg->modi = (arg->modi == *handler) ? (*handler - 32) : *handler;
	else if (ft_strchr("diuxXcspo%", *handler) && !arg->conv)
		arg->conv = *handler;
	else
		return (0);
	return (1);
}
