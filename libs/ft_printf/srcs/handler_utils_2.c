/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:32:12 by llaurent          #+#    #+#             */
/*   Updated: 2020/01/27 17:36:48 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handler_buff(char *buffer, t_arg *arg, int *count)
{
	int	i;

	i = ft_strlen(buffer);
	if (arg->conv == 'c')
		handle_c(buffer, arg, count, i);
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
		handle_o(buffer, arg, count, i);
}
