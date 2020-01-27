/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:34:32 by llaurent          #+#    #+#             */
/*   Updated: 2020/01/27 13:33:07 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <libc.h>
#include "get_next_line.h"
#include "structures.h"
#include "defines.h"
#include "libft.h"

int		parse_line(t_data *data);
t_data	*init_struct();
#endif
