/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:04:08 by llaurent          #+#    #+#             */
/*   Updated: 2020/01/27 15:08:14 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	command_exists(char *command)
{
	if ((ft_strcmp(command, "echo") == 0) || (ft_strcmp(command, "cd") == 0)
	|| (ft_strcmp(command, "pwd") == 0) || (ft_strcmp(command, "export") == 0)
	|| (ft_strcmp(command, "unset") == 0) || (ft_strcmp(command, "env") == 0)
	|| (ft_strcmp(command, "exit") == 0))
		return (1);
	return (0);
}

int	get_command(t_data *data)
{
	int		start;
	int		len;

	start = 0;
	while (data->line[start] == ' ')
		start++;
	len = 0;
	while (data->line[len + start] && data->line[len + start] != ' ')
		len++;
	data->command = ft_substr(data->line, start, len);
	return (command_exists(data->command));
}

int	get_arguments(t_data *data)
{
	char	*arguments;
	int		index;

	index = ft_strlen(data->command);
	arguments = data->line + index;
	while (data->line[index++] == ' ')
		arguments++;
	return (1);
}

int	exec_command(t_data *data)
{
	if (ft_strcmp(data->command, "exit") == 0)
		exit(EXIT_SUCCESS);
	if (ft_strcmp(data->command, "env") == 0)
		get_env(data);
	if (ft_strcmp(data->command, "pwd") == 0)
		get_pwd(data);

	return (1);
}

int	parse_line(t_data *data)
{
	if (get_command(data) == 0)
		ft_putstr(COMMAND_NOT_FOUND);
	get_arguments(data);
	exec_command(data);
	return (1);
}