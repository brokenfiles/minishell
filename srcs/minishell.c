/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:33:44 by llaurent          #+#    #+#             */
/*   Updated: 2020/01/27 13:30:45 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	ft_putstr(PRE_LINE);
	while (get_next_line(0, &(data.line)) > 0)
	{
		if (ft_strncmp(data.line, "exit", 4) == 0)
			exit(EXIT_SUCCESS);
		free(data.line);
		ft_putstr(PRE_LINE);
	}
	free(data.line);
	return (EXIT_SUCCESS);
}