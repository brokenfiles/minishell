/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:07:50 by mbrignol          #+#    #+#             */
/*   Updated: 2020/03/01 18:07:50 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redirect	*has_only_reg(t_redirect *begin)
{
	struct stat	buff;
	t_redirect	*current;
	int			ret;

	current = NULL;
	while (begin)
	{
		if (begin->type == LEFT_AQUOTE)
		{
			current = begin;
			ret = stat(current->file, &buff);
			if (ret == -1 || !S_ISREG(buff.st_mode))
			{
				error_command_nf(current->file);
				return (NULL);
			}
			if (!(buff.st_mode & S_IRUSR))
			{
				error_file_np(current->file);
				return (NULL);
			}
		}
		begin = begin->next;
	}
	return (current);
}
