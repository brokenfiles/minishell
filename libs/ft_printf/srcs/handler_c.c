/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:44 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/26 09:58:33 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_c(char *buffer, t_arg *arg, int *count, int i)
{
	i = 0;
	if (arg->width1 < 0)
	{
		arg->flag = '-';
		arg->width1 = -arg->width1;
	}
	if (arg->width1 && arg->flag != '-')
		padding(' ', arg->width1 - 1, count);
	ft_putchar_count(buffer[0], count);
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - 1, count);
}

void	handle_100(char *buffer, t_arg *arg, int *count, int i)
{
	if (arg->width1 < 0)
	{
		arg->flag = '-';
		arg->width1 = -arg->width1;
	}
	if (arg->width1 && arg->flag != '-')
		(arg->flag == '0') ? padding('0', arg->width1 - i, count) :
		padding(' ', arg->width1 - i, count);
	ft_putstr_count(buffer, count, arg->width2);
	if (arg->width1 && arg->flag == '-')
		padding(' ', arg->width1 - i, count);
}
