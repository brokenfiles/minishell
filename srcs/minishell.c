/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:33:44 by llaurent          #+#    #+#             */
/*   Updated: 2020/01/27 16:21:32 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	data = init_struct(env);
	ft_putstr(PRE_LINE);
	while (get_next_line(0, &(data->line)) > 0)
	{
		parse_line(data);
		free(data->line);
		ft_putstr(PRE_LINE);
	}
	free(data->line);
	return (EXIT_SUCCESS);
}