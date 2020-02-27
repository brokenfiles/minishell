/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:53 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_p(char *buffer, t_arg *arg, int *count, int i)
{
	i += (arg->precision == '.' && arg->w2 > arg->w1 ? 0 : 2);
	if (arg->w1 && arg->flag != '-')
		(arg->flag == '0') ? padding('0', arg->w1 - i, count) :
		padding(' ', arg->w1 - i, count);
	ft_putstr_count("0x", count, 0);
	if (arg->w2)
		padding('0', arg->w2 - i, count);
	if (!(buffer[0] == '0' && arg->precision == '.' && !arg->w2))
		ft_putstr_count(buffer, count, 0);
	if (arg->w1 && arg->flag == '-')
		padding(' ', arg->w1 - i, count);
}

void	padding_space_af(t_arg *arg, int i, int *count, char *buffer)
{
	int size;

	size = (arg->w2 > i) ? arg->w2 : i;
	size += (arg->pos == '#' && buffer[0] != '0') ? 2 : 0;
	if (arg->w1 && arg->flag == '-')
		padding(' ', arg->w1 - size, count);
}

void	padding_front(t_arg *arg, int *count, int i, char *buffer)
{
	int size;

	size = (arg->w2 > i) ? arg->w2 : i;
	if (arg->w2 && arg->w1 && arg->pos == '#' && buffer[0] != '0')
		size += 2;
	if (arg->flag != '-' && arg->w1 && (arg->precision == '.' ||
	arg->flag != '0'))
		padding(' ', arg->w1 - size, count);
	else if (arg->w1 && arg->flag != '-'
	&& (arg->pos != '#' || buffer[0] == '0'))
		padding('0', arg->w1 - size, count);
}

void	handle_x(char *buffer, t_arg *arg, int *count, int i)
{
	int	j;

	arg->w2 += (arg->pos == '#' && arg->w1
	&& (arg->precision != '.' || !arg->w2) && buffer[0] != '0' ? 2 : 0);
	j = i;
	if (buffer[0] == '-')
		i = 8;
	padding_front(arg, count, i, buffer);
	if (arg->pos == '#' && buffer[0] != '0')
		ft_putstr_count(arg->conv == 'x' ? "0x" : "0X", count, 0);
	if (arg->w2 > 0 && arg->precision == '.')
		padding('0', arg->w2 - i, count);
	else if (arg->w1 > 0 && arg->pos == '#'
	&& buffer[0] != '0' && arg->flag == '0')
		padding('0', arg->w1 - i - 2, count);
	if (buffer[0] == '-' && buffer++)
		padding((arg->conv == 'x') ? 'f' : 'F', 8 - j + 1, count);
	if (!(buffer[0] == '0' && arg->precision == '.' && !arg->w2))
		ft_putstr_count(buffer, count, 0);
	else if (arg->w1 && arg->precision == '.')
		ft_putchar_count(' ', count);
	padding_space_af(arg, i, count, buffer);
}
