#include "../../includes/minishell.h"

int		exec_only_one(t_data *data, char **cmds)
{
	pid_t	pid;

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
	pid_t	pid;
	pid_t	pid2;
	int		pipefd[2];
	int		save[2];
	char	**cmds;

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

void	redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) != -1)
			close(oldfd);
	}
}

void    exec_pipeline(char ***cmds, char **env, int pos, int in_fd, t_data *data)
{
	pid_t	process;
	int		fd[2];

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
	split = ft_split_spec(data->line, '|');
	commands = malloc(sizeof(char**) * (tabsize(split) + 1));
	while (i < tabsize(split))
	{
		commands[i] = ft_split_spec(split[i], ' ');
		i++;
	}
	commands[i] = NULL;
//	if (tabsize(split) == 1) maybe ????
//		run_command(data, commands[0]); maybe ???
//	else maybe ???
//	{ maybe ???
		if ((pid = fork()) == -1)
			return (0);
		if (pid == 0)
			exec_pipeline(commands, data->env, 0, STDIN_FILENO, data);
		wait(NULL);
//	} maybe ???
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

}