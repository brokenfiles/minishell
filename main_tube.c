#include "includes/minishell.h"

void    redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) != -1)
			close(oldfd);
	}
}

void    exec_pipeline(char ***cmds, char **env, int pos, int in_fd)
{
	pid_t   process;
	int     fd[2];
	int     status;

	if (cmds[pos + 1] == NULL)
	{

		redirect(in_fd, STDIN_FILENO);
		execve(cmds[pos][0], cmds[pos], env);
	}
	else
	{
		pipe(fd);
		process = fork();
//		ft_putstr("[Process : "); ft_putnbr_fd(process, 1); ft_putstr("]\n");
		if (process == 0)
		{
//			ft_putstr("[Processus Fils]\n");
			close(fd[0]);
			redirect(in_fd, STDIN_FILENO);
			redirect(fd[1], STDOUT_FILENO); // entree tunnel = fd 1
			execve(cmds[pos][0], cmds[pos], env);
		}
		else
		{
//			ft_putstr("[Processus Père]\n");
			waitpid(process, &status, 0);
//			ft_putstr("[After waitpid]\n");
			close(fd[1]);
			close(in_fd);
			exec_pipeline(cmds, env, pos + 1, fd[0]);
		}
	}
}

int     main(int ac, char **av, char **env)
{
	char    ***commands;
	int     i;
	int     j;

	i = -1;
	if (!(commands = (char***)malloc(sizeof(char**) * ac)))
		return (0);
	commands[ac - 1] = NULL;
	while (++i < ac - 1)
		commands[i] = ft_split(av[i + 1], ' ');
	exec_pipeline(commands, env, 0, STDIN_FILENO);
	return (0);
}

