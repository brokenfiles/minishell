/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:32:01 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/26 10:25:20 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	reset_arg_param(t_arg *arg)
{
	arg->conv = 0;
	arg->flag = 0;
	arg->precision = 0;
	arg->modi = 0;
	arg->width1 = 0;
	arg->width2 = 0;
	arg->flag_s = 0;
}
