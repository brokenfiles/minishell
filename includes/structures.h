/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:28:08 by llaurent          #+#    #+#             */
/*   Updated: 2020/01/27 16:21:32 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct	s_data
{
	char	**env;
	char	*line;
	char	*command;
	char	*arguments;
	char	cwd[PATH_MAX];
}				t_data;
#endif
