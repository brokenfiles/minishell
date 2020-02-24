/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:27 by mbrignol          #+#    #+#             */
/*   Updated: 2020/02/24 14:06:19 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		free_string(char **str, int value)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (value);
}

int		free_buffer(char *buffer, int value)
{
	free(buffer);
	return (value);
}

int		ft_read_fd(int fd, char **str)
{
	char	*buffer;
	char	*temp;
	int		size_read;

	if (!(buffer = ft_strnew(BUFFER_SIZE)))
		return (FAILURE);
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read <= 0)
		return (free_buffer(buffer, size_read));
	if (buffer[0] == 0)
		return (free_buffer(buffer, 0));
	buffer[size_read] = '\0';
	if (!(temp = ft_strnew(ft_strlen(*str) + size_read)))
		return (FAILURE);
	if (*str)
	{
		temp = ft_strncat(temp, *str, ft_strlen(*str));
		free(*str);
	}
	*str = ft_strncat(temp, buffer, size_read);
	free(buffer);
	if (!ft_is_line(*str))
		return (ft_read_fd(fd, str));
	return (SUCCESS);
}

int		ft_split_str(char **str, char **line)
{
	char	*temp;
	char	*temp_line;
	int		size_line;
	int		size_rest;

	size_line = 0;
	while ((*str)[size_line] && (*str)[size_line] != '\n')
		size_line++;
	if (!(temp_line = ft_strnew(size_line)))
		return (FAILURE);
	*line = ft_strncat(temp_line, *str, size_line);
	size_rest = ft_strlen(*str) - size_line;
	if (size_rest == 0)
		return (free_string(str, END));
	if ((temp = ft_strnew(size_rest)))
	{
		temp = ft_strncat(temp, &(*str)[size_line + 1], size_rest - 1);
		free(*str);
		*str = temp;
		return (SUCCESS);
	}
	return (free_string(str, FAILURE));
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	int				cut;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (FAILURE);
	if (!ft_is_line(str))
	{
		if (ft_read_fd(fd, &str) == FAILURE)
			return (FAILURE);
		if (!str)
		{
			*line = ft_strnew(0);
			return (END);
		}
	}
	if ((cut = ft_split_str(&str, line)) != SUCCESS)
		return (free_string(&str, END));
	return (SUCCESS);
}
