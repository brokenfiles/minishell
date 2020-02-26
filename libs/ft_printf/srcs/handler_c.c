/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:44 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2020/02/26 10:59:26 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_c(char *buffer, t_arg *arg, int *count)
{
<<<<<<< HEAD
	i = 0;
=======
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
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
