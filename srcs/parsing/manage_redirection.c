#include "../../includes/minishell.h"

<<<<<<< HEAD
int		exec_only_one(t_data *data, char **cmds)
{
	pid_t pid;

	if ((pid = fork()) == -1)
		return (0);
	if (pid == 0)
	{
		run_command(data, cmds);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	return (0);
}

int		exec_pipes(t_data *data, char **split, int x)
{
	pid_t pid;
	pid_t pid2;
	int pipefd[2];
	int save[2];
	char **cmds;

	if (pipe(pipefd) == -1)
		return(0);
	cmds = ft_split_spec(split[x++], ' ');
	if ((pid = fork()) == -1)
		return (0);
	if (pid == 0)
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		run_command(data, cmds);
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	wait(NULL);
	free_splitted(cmds, 0);
	cmds = ft_split_spec(split[x++], ' ');
	pid2 = fork();
	if (pid2 == -1)
		printf("fork error");
	if (pid2 == 0)
	{
		save[0] = dup(0);
		dup2(pipefd[0], STDIN_FILENO);
		run_command(data, cmds);
	}
	wait(NULL);
	free_splitted(cmds, 0);
	dup2(save[0], 0);
	close(pipefd[0]);
	return (0);
}

void    redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) != -1)
=======
int		is_built_in(char *str)
{
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	return (0);
}

int		redirect_output(t_redirect *redirect)
{
	int	fd;

	if (!(fd = open(redirect->file, redirect->type == DOUBLE_AQUOTE ? O_RDWR | O_CREAT | O_APPEND
				: O_RDWR | O_CREAT | O_TRUNC, 0644)))
		return (-1);
	if (dup2(fd, STDOUT_FILENO) < 1)
		return (-1);
	return (fd);
}

void	redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
			close(oldfd);
	}
}

<<<<<<< HEAD
void    exec_pipeline(char ***cmds, char **env, int pos, int in_fd, t_data *data)
{
	pid_t   process;
	int     fd[2];

	if (cmds[pos + 1] == NULL)
	{
		redirect(in_fd, STDIN_FILENO);
		run_command(data, cmds[pos]);
		exit(EXIT_FAILURE);
	}
	else
	{
		pipe(fd);
		process = fork();
		if (process == 0)
		{
			close(fd[0]);
			redirect(in_fd, STDIN_FILENO);
			redirect(fd[1], 1);
			run_command(data, cmds[pos]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			close(in_fd);
			exec_pipeline(cmds, env, pos + 1, fd[0], data);
		}
	}
}

int		exec_hub(t_data *data)
{
//	pid_t pid;
//	char ***commands;

/*------------- V1 -----------*/
/*
	char **cmds;
	char **split;
	int x;


	x = 0;
	split = ft_split(data->line, '|');
	while (split[x])
	{
		cmds = ft_split_spec(split[x], ' ');
		if (split[x + 1] == 0)
		{
			exec_only_one(data, cmds);
			free_splitted(split, 0);
			free_splitted(cmds, 0);
			return (0);
		}
		if (split[x + 1])
		{
			exec_pipes(data, split, x);
			return (0);
		}
		x++;
	}
	return (EXIT_SUCCESS);
 */
/*------------- V1 -----------*/
/*------------- V2 -----------*/

	pid_t pid;
	int i;
	char ***commands;
	char **split;

	i = 0;
	split = ft_split(data->line, '|');
	commands = malloc(sizeof(char**) * (tabsize(split) + 1));
	while (i < tabsize(split))
	{
		commands[i] = ft_split(split[i], ' ');
		i++;
	}
	commands[i] = NULL;
	if ((pid = fork()) == -1)
		return (0);
	if (pid == 0)
		exec_pipeline(commands, data->env, 0, STDIN_FILENO, data);
	wait(NULL);
	i = 0;
	while (i < tabsize(split))
	{
		free_splitted(commands[i], 0);
		i++;
	}
	free(commands);
	free_splitted(split, 0);
	return (EXIT_SUCCESS);
/*------------- V2 -----------*/

=======
int is_command_alone(char ***cmds, int pos, int in_fd, t_data *data)
{
	pid_t	process;

	if (is_built_in(cmds[pos][0]) == 0)
	{
		process = fork();
		if (process == 0)
		{
			if (is_right_arrow(data->tPipe[pos].redirect) == 1)
				data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
			if (is_left_arrow(data->tPipe[pos].redirect))
			{
				if (handle_left_arrow(data, data->tPipe[pos].redirect, 0) == EXIT_FAILURE)
				{
					ft_putstr_fd("minishell: no such file or directory\n", 2);
					exit(0);
					return (EXIT_FAILURE);
				}
			}
			if (!is_right_arrow(data->tPipe[pos].redirect) && !is_left_arrow(data->tPipe[pos].redirect))
				redirect(in_fd, STDIN_FILENO);
			if (pos > 0)
				close(in_fd);
			run_command(data, cmds[pos]);
			exit(EXIT_SUCCESS);
		}

	}
	else
	{
		if (is_right_arrow(data->tPipe[pos].redirect))
		{
			data->fd[0] = dup(1);
			data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
			run_command(data, cmds[pos]);
			dup2(data->fd[0], 1);
			close(data->fd[0]);
			close(data->fd[1]);
		}
		else
			run_command(data, cmds[pos]);
	}
	return (EXIT_SUCCESS);
}

int is_pipeline(char ***cmds, int pos, int in_fd, t_data *data)
{
	pid_t	process;

	process = fork();
	if (process == 0)
	{
		redirect(in_fd, STDIN_FILENO);
		if (is_right_arrow(data->tPipe[pos].redirect))
			data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
		if (is_left_arrow(data->tPipe[pos].redirect))
		{
			if (handle_left_arrow(data, data->tPipe[pos].redirect, 1) == EXIT_FAILURE)
			{
				ft_putstr_fd("minishell: no such file or directory\n", 2);
				exit(0);
				return (EXIT_FAILURE);
			}
		}
		close(data->pipe[1]);
		run_command(data, cmds[pos]);
		exit(EXIT_SUCCESS);
	}
	close(in_fd);
	return (EXIT_SUCCESS);
}

int	exec_fils(char ***cmds, int pos, int in_fd, t_data *data)
{
	close(data->pipe[0]);
	redirect(in_fd, STDIN_FILENO);
	if (is_right_arrow(data->tPipe[pos].redirect))
		data->fd[1] = handle_right_arrow(data->tPipe[pos].redirect);
	if (is_left_arrow(data->tPipe[pos].redirect))
	{
		if (handle_left_arrow(data, data->tPipe[pos].redirect, 1) == EXIT_FAILURE)
		{
			ft_putstr_fd("minishell: no such file or directory\n", 2);
			exit(0);
			return (EXIT_FAILURE);
		}
	}
	if (!is_right_arrow(data->tPipe[pos].redirect) && !is_left_arrow(data->tPipe[pos].redirect))
		redirect(data->pipe[1], 1);
	close(data->pipe[1]);
	run_command(data, cmds[pos]);
	exit(EXIT_FAILURE);
}

int	exec_papa(char ***cmds, int pos, int in_fd, t_data *data)
{
	if (pos > 0)
		close(in_fd);
	close(data->pipe[1]);
	exec_pipeline(cmds, pos + 1, data->pipe[0], data);
	return (EXIT_SUCCESS);
}

int	exec_pipeline(char ***cmds, int pos, int in_fd, t_data *data)
{
	pid_t	process;
	int		end;

	end = 0;
	process = -1;
	if (cmds[pos + 1] == NULL)
	{
		if (pos > 0)
		{
			if (is_pipeline(cmds, pos, in_fd, data) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
		{
			if (is_command_alone(cmds, pos, in_fd, data) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		while (end != -1)
			end = waitpid(process, &data->last_return, 0);
		handle_return(data);
	}
	else
	{
		pipe(data->pipe);
		process = fork();
		if (process == 0)
		{
			if (exec_fils(cmds, pos, in_fd, data) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
		{
			if (exec_papa(cmds, pos, in_fd, data) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int exec_hub(t_data *data)
{
	int		i;
	int		x;
	char	***commands;
	char	**split;

	i = 0;
	if (!(split = ft_split_spec(data->line, '|')))
		return (EXIT_FAILURE);
	if (!(commands = malloc(sizeof(char **) * (tabsize(split) + 1))))
		return (free_splitted(split, EXIT_FAILURE));
	while (i < tabsize(split))
	{
		x = 0;
		if (redirection_hub(data, &split[i], i) == EXIT_FAILURE)
		{
			free_splitted(split, 0);
			free(commands);
			return (EXIT_FAILURE);
		}
		commands[i] = ft_split_spec(split[i], ' ');
		while (commands[i][x])
			remove_quotes(&commands[i][x++]);
		i++;
	}
	commands[i] = NULL;
	if (exec_pipeline(commands, 0, STDIN_FILENO, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < tabsize(split))
		free_splitted(commands[i++], 0);
	free(commands);
	free_splitted(split, 0);
	i = 0;
	while (i < tabsize(split))
		ft_lstclear_redirect(&data->tPipe[i++].redirect, free);
	return (EXIT_SUCCESS);
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
}