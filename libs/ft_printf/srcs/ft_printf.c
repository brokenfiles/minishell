/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:31 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/26 13:38:26 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_printf(const char *str, ...)
{
	va_list		va;
	t_arg		arg;
	int			count;

	count = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			reset_arg_param(&arg);
			str++;
			while (set_arg_param(&arg, &*((char *)str), va) && *str)
				str++;
			handler_arg(va, &arg, &count);
		}
		else
			ft_putchar_count(*(str++), &count);
	}
	va_end(va);
	return (count);
}
