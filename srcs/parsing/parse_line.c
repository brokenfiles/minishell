/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:41:25 by llaurent          #+#    #+#             */
/*   Updated: 2020/02/27 19:26:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_return(t_data *data)
{
	if (data->last_return == EXIT_FAILURE || data->last_return == EXIT_SUCCESS)
		return ;
	if (data->last_return == 11 || data->last_return == 10)
		data->last_return += 128;
	else if (data->last_return == 32512)
		data->last_return = 127;
	else
		data->last_return = 1;
}

int		run_command(t_data *data, char **cmds)
{
	if (ft_strcmp(cmds[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(cmds[0], "env") == 0)
		data->last_return = exec_env(data, cmds);
	else if (ft_strcmp(cmds[0], "pwd") == 0)
		data->last_return = exec_pwd(data);
	else if (ft_strcmp(cmds[0], "cd") == 0)
		data->last_return = exec_cd(data, cmds);
	else if (ft_strcmp(cmds[0], "echo") == 0)
		data->last_return = exec_echo(cmds);
	else if (ft_strcmp(cmds[0], "unset") == 0)
		data->last_return = exec_unset(data, cmds);
	else if (ft_strcmp(cmds[0], "export") == 0)
		data->last_return = exec_export(data, cmds);
	else if (exec_prog(data, cmds, &data->last_return) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		parse_line(t_data *data)
{
	char	**commands;
	int		index;

	index = 0;
	if (!(commands = ft_split_spec(data->line, ';')))
		return (EXIT_FAILURE);
	while (commands[index])
	{
		if (data->line)
			free(data->line);
		if (!(data->line = ft_strdup(commands[index])))
			return (free_splitted(commands, EXIT_FAILURE));
		if (exec_hub(data) == EXIT_FAILURE)
		{
			data->last_return = EXIT_FAILURE;
			return (free_splitted(commands, EXIT_FAILURE));
		}
		index++;
	}
	free_splitted(commands, 0);
	return (EXIT_SUCCESS);
}
