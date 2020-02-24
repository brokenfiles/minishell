/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:32:12 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/24 14:06:19 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	set_buff(va_list va, t_arg *arg, int *count)
{
	char *buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * 1)))
		return ;
	bzero((void *)buffer, ft_strlen(buffer));
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
	free(buffer);
}

void	handler_buff(char *buffer, t_arg *arg, int *count)
{
	int	i;

	i = ft_strlen(buffer);
	if (arg->conv == 'c')
		handle_c(buffer, arg, count);
	else if (arg->conv == '%')
		handle_100(buffer, arg, count, i);
	else if (arg->conv == 'd' || arg->conv == 'i')
		handle_di(buffer, arg, count, i);
	else if (arg->conv == 'u')
		handle_u(buffer, arg, count, i);
	else if (arg->conv == 's')
		handle_s(buffer, arg, count, i);
	else if (arg->conv == 'x' || arg->conv == 'X')
		handle_x(buffer, arg, count, i);
	else if (arg->conv == 'P')
		handle_p(buffer, arg, count, i);
	else if (arg->conv == 'o')
		handle_o(buffer, arg, count);
}
