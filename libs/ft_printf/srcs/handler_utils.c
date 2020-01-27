/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:32:06 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/26 17:37:47 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	padding(char c, int len, int *count)
{
	while (len-- > 0)
		ft_putchar_count(c, count);
}

void	handler_arg(va_list va, t_arg *arg, int *count)
{
	char *buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * 1)))
		return ;
	if (arg->conv == 'c')
		ft_strjoin_c(&buffer, (char)(va_arg(va, int)));
	else if (arg->conv == '%')
		ft_strjoin_c(&buffer, '%');
	else if (arg->conv == 'd' || arg->conv == 'i')
		ft_putnbr_buff(&buffer, va_arg(va, int));
	else if (arg->conv == 'u')
		ft_putnbr_u_buff(&buffer, va_arg(va, unsigned int));
	else if (arg->conv == 's')
		ft_putstr_buff(&buffer, va_arg(va, char *));
	else if (arg->conv == 'x' || arg->conv == 'X')
		ft_puthexa_buff(&buffer, (long int)va_arg(va, int), arg, 0);
	else if (arg->conv == 'p')
		ft_puthexa_buff(&buffer, va_arg(va, long int), arg, 0);
	else if (arg->conv == 'o')
		ft_putoctal_buff(&buffer, va_arg(va, int));
	handler_buff(buffer, arg, count);
	ft_bzero((void *)buffer, ft_strlen(buffer));
	free(buffer);
}

void	priv_fct_2(char *handler, t_arg *arg, va_list va)
{
	if (*handler == '*' && arg->width1 == 0 &&
		!arg->flag_s && arg->precision != '.')
	{
		arg->width1 = va_arg(va, int);
		arg->flag_s = 1;
	}
	else if (*handler == '*' && !arg->width2)
		arg->width2 = va_arg(va, int);
	else
		arg->precision = '.';
}

int		set_arg_param(t_arg *arg, char *handler, va_list va)
{
	if (ft_strchr("#0-", *handler) &&
		(!arg->flag || (arg->flag == '-' && *handler == '-')) &&
		!arg->width1 && !arg->width2 && !arg->conv)
		arg->flag = *handler;
	else if (ft_isdigit(*handler) && !arg->width1 && !arg->precision &&
	!arg->conv && !arg->width2 && !arg->modi)
		arg->width1 = ft_atoi((const char *)handler);
	else if (ft_isdigit(*handler) && !arg->precision && !arg->conv)
		return (1);
	else if (ft_strchr(".*", *handler) && !arg->conv)
		priv_fct_2(handler, arg, va);
	else if (ft_isdigit(*handler) && !arg->width2 && !arg->modi && !arg->conv)
		arg->width2 = ft_atoi((const char *)handler);
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
