/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:07:27 by mbrignol          #+#    #+#             */
/*   Updated: 2020/03/01 18:07:27 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		exec_env(t_data *data, char **cmds)
{
	char	**tmp;

	tmp = data->env;
	if (!tmp || !*tmp)
		return (EXIT_FAILURE);
	if (tabsize(cmds) > 1)
	{
		ft_printf("env: '%s': no such file or directory\n", cmds[1]);
		return (EXIT_FAILURE);
	}
	while (*tmp)
		ft_printf("%s\n", *(tmp++));
	return (EXIT_SUCCESS);
}
