/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:08:23 by mbrignol          #+#    #+#             */
/*   Updated: 2020/03/01 18:08:23 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_nb_redirect(char *str)
{
	int	index;
	int	nb;

	nb = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] && (str[index] == '<' || str[index] == '>'))
		{
			nb++;
			while (str[index] && (str[index] == '<' || str[index] == '>'))
				index++;
		}
		else
			index++;
	}
	return (nb);
}
