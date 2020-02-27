/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:57 by jchotel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
.fr       */
=======
/*   Updated: 2020/02/26 10:59:26 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
=======
/*   Updated: 2020/02/26 17:33:24 by llaurent         ###   ########.fr       */
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_s(char *buffer, t_arg *arg, int *count, int i)
{
	if (arg->flag != '-')
		padding((arg->flag == '0' ? '0' : ' '), arg->w1 -
		((arg->w2 < i && (arg->w2 > 0 || arg->precision == '.')
		&& arg->w2 >= 0) ? arg->w2 : i), count);
	if (!(arg->precision == '.' && arg->w2 == 0))
		ft_putstr_count(buffer, count, (i < arg->w2 && arg->precision
		== '.') ? i : arg->w2);
	if (arg->flag == '-')
		padding(' ', arg->w1 - ((arg->w2 < i && arg->w2 >= 0 &&
		arg->precision == '.') ? arg->w2 : i), count);
}
