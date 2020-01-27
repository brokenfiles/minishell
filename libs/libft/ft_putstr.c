/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:22:08 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/27 11:41:08 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr(char *str)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
}
