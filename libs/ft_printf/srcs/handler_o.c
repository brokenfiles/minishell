/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:49 by llaurent          #+#    #+#             */
/*   Updated: 2019/11/25 12:31:49 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_o(char *buffer, t_arg *arg, int *count, int i)
{
	i = 0;
	ft_putstr_count(buffer, count, arg->width2);
}
