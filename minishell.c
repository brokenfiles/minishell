/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:39:24 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/27 12:40:10 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/minishell.h"

int main(int ar, char **argv, char **env)
{
	char *line;
	while (get_next_line(0, &line))
	{
		printf("%s\n", line);
		free(line);
	}
}