/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:52:44 by jchotel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/26 11:28:13 by llaurent         ###   ########.fr       */
rignol         ###   ########.fr       */
=======
/*   Updated: 2020/02/26 10:59:26 by mbrignol         ###   ########.fr       */
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7:libs/ft_printf/srcs/ft_put.c
=======
/*   Updated: 2020/02/26 17:33:24 by llaurent         ###   ########.fr       */
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr_buff(char **buffer, int nb)
{
	unsigned int	a;

	a = (nb < 0) ? -nb : nb;
	(nb < 0) ? ft_strjoin_c(buffer, '-') : 0;
	(a > 9) ? ft_putnbr_buff(buffer, (int)(a / 10)) : 0;
	ft_strjoin_c(buffer, a % 10 + '0');
}

void	ft_putnbr_u_buff(char **buffer, unsigned int nb)
{
	(nb > 9) ? ft_putnbr_u_buff(buffer, (unsigned int)(nb / 10)) : 0;
	ft_strjoin_c(buffer, nb % 10 + '0');
}

void	ft_putstr_buff(char **buffer, char *str)
{
	int index;
	char *tmp;

	tmp = NULL;
	index = 0;
	if (!str)
	{
		tmp = ft_strdup("(null)");
		while (tmp[index])
		{
			ft_strjoin_c(buffer, tmp[index]);
			index++;
		}
		free(tmp);
		return;
	}
	while (str[index])
		ft_strjoin_c(buffer, str[index++]);
}

void	ft_putstr_count(char *str, int *count, int len)
{
	int	index;

	index = 0;
	if (len > 0)
		while (str[index] && index < len)
		{
			write(1, &str[index++], 1);
			(*count)++;
		}
	else
		while (str[index])
		{
			write(1, &str[index++], 1);
			(*count)++;
		}
}
