/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:08:00 by mbrignol          #+#    #+#             */
/*   Updated: 2020/03/01 18:08:53 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_build_in(t_data *data, int pos, int in_fd, char ***cmds)
{
	pid_t	process;

	process = fork();
	if (process == 0)
	{
		if (is_right_arrow(data->tpipe[pos].redirect) == 1)
			if ((data->fd[1] = handle_right_arrow(data->tpipe[pos].redirect))
			== -1)
				exit(EXIT_FAILURE);
		if (is_left_arrow(data->tpipe[pos].redirect))
		{
			if (handle_left_arrow(data, data->tpipe[pos].redirect, 0)
			== EXIT_FAILURE)
				exit(0);
		}
		if (!is_right_arrow(data->tpipe[pos].redirect) &&
		!is_left_arrow(data->tpipe[pos].redirect))
			redirect(in_fd, STDIN_FILENO);
		if (pos > 0)
			close(in_fd);
		run_command(data, cmds[pos]);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	is_command_alone(char ***cmds, int pos, int in_fd, t_data *data)
{
	if (is_built_in(cmds[pos][0]) == 0)
		handle_build_in(data, pos, in_fd, cmds);
	else
	{
		if (is_right_arrow(data->tpipe[pos].redirect))
		{
			data->fd[0] = dup(1);
			if ((data->fd[1] = handle_right_arrow(data->tpipe[pos].redirect))
			== -1)
				return (EXIT_SUCCESS);
			run_command(data, cmds[pos]);
			dup2(data->fd[0], 1);
			close(data->fd[0]);
			close(data->fd[1]);
		}
		if (is_left_arrow(data->tpipe[pos].redirect))
		{
			if (!(has_only_reg(data->tpipe[pos].redirect)))
				return (EXIT_SUCCESS);
			run_command(data, cmds[pos]);
		}
		if (!is_right_arrow(data->tpipe[pos].redirect) &&
			!is_left_arrow(data->tpipe[pos].redirect))
			run_command(data, cmds[pos]);
	}
	return (EXIT_SUCCESS);
}

int	is_pipeline(char ***cmds, int pos, int in_fd, t_data *data)
{
	pid_t	process;

	process = fork();
	if (process == 0)
	{
		redirect(in_fd, STDIN_FILENO);
		if (is_right_arrow(data->tpipe[pos].redirect) == 1)
			if ((data->fd[1] = handle_right_arrow(data->tpipe[pos].redirect))
			== -1)
				exit(EXIT_FAILURE);
		if (is_left_arrow(data->tpipe[pos].redirect))
			if (handle_left_arrow(data, data->tpipe[pos].redirect, 1)
				== EXIT_FAILURE)
				exit(EXIT_FAILURE);
		close(data->pipe[1]);
		run_command(data, cmds[pos]);
		exit(EXIT_SUCCESS);
	}
	close(in_fd);
	return (EXIT_SUCCESS);
}
