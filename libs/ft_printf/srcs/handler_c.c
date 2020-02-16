/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:44 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/14 22:18:44 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_c(char *buffer, t_arg *arg, int *count)
{
	if (arg->w1 && arg->flag != '-')
		padding(' ', arg->w1 - 1, count);
	ft_putchar_count(buffer[0], count);
	if (arg->w1 && arg->flag == '-')
		padding(' ', arg->w1 - 1, count);
}

void	handle_100(char *buffer, t_arg *arg, int *count, int i)
{
	if (arg->w1 && arg->flag != '-')
		(arg->flag == '0') ? padding('0', arg->w1 - i, count) :
		padding(' ', arg->w1 - i, count);
	ft_putstr_count(buffer, count, arg->w2);
	if (arg->w1 && arg->flag == '-')
		padding(' ', arg->w1 - i, count);
}
