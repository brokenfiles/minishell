/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:41:19 by llaurent          #+#    #+#             */
/*   Updated: 2020/01/27 15:03:52 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*init_struct(char **env)
{
	t_data	*data;

	if (!(data = malloc(sizeof(struct s_data))))
		return (NULL);
	if (!(getcwd(data->cwd, sizeof(data->cwd))))
		return (NULL);
	data->env = env;
	return (data);
}