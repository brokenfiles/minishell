/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:31:36 by jchotel           #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*ft_strdup_size(const char *s, size_t len)
{
	char	*new;
	size_t	i;

	i = ft_strlen((char *)s);
	if (!(new = (char *)malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

void		ft_strjoin_c(char **s1, char s2)
{
	char	*copy;
	size_t	i;

	if (!s2)
		return ;
	i = ft_strlen(*s1);
	copy = ft_strdup_size(*s1, i + 2);
	copy[i] = s2;
	copy[i + 1] = '\0';
	free(*s1);
	*s1 = copy;
}
