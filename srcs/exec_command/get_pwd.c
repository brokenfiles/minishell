/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:17:11 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/27 16:21:32 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_pwd(t_data *data)
{
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (0);
	ft_putstr(data->cwd);
	ft_putchar('\n');
	return (1);
}
