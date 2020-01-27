/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:54:09 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/27 15:09:02 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_env(t_data *data)
{
	int i;

	i = 0;
	while (data->env[i])
	{
		ft_putstr(data->env[i++]);
		ft_putchar('\n');
	}
	return (1);
}