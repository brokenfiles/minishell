/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:07:26 by mbrignol          #+#    #+#             */
/*   Updated: 2020/03/01 18:07:26 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		exec_echo(char **cmds)
{
	int	x;
	int	is_n;
	int	len;

	is_n = 0;
	x = 1;
	if ((len = tabsize(cmds)) >= 2 && ft_strcmp(cmds[1], "-n") == 0)
		is_n = 1;
	if (is_n)
		x++;
	while (cmds[x])
		len - 1 != x ? ft_printf("%s ", cmds[x++]) : ft_printf("%s", cmds[x++]);
	if (!is_n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
