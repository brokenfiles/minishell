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
		if (process == 0)
		{
			close(fd[0]);
			redirect(in_fd, STDIN_FILENO);
			redirect(fd[1], STDOUT_FILENO);
			ft_putstr_fd(cmds[pos][0], 2);
			execve(cmds[pos][0], cmds[pos], env);
		}
		else
		{
			waitpid(process, &status, 0);
			close(fd[1]);
			close(in_fd);
			ft_putstr_fd(cmds[pos][0], 2);
			exec_pipeline(cmds, env, pos + 1, fd[0]);
		}
	}
}

int		stay(void)
{
	int pipefd[2];
	int save[2];
	char **cmds;
	char **cmds2;
	char **split;
	split = ft_split(data->line, '|');
	cmds = ft_split_spec(split[0], ' ');
	cmds2 = ft_split(split[1], ' ');
//	char buf[200] = {0};

	pid_t pid;
	pid_t pid2;
	if (pipe(pipefd) == -1) //J'ouvre le pipe
		printf("pipe error");
	pid = fork();
	if (pid == -1)
		printf("fork error");
	if (pid == 0) //Dans le child
	{
		dup2(pipefd[1], 1);
		//Ici je veut que ls sois envoyer sur pipefd[0]. Vue que ls ecris
		// sur STDOUT, je dois remplacer STDOUT par mon pipe de write
		close(pipefd[0]); //Je ferme les deux, car je n'en ai plus besoin,
		close(pipefd[1]); //Celui utile a deja ete dup.
		run_command(data, cmds);
		//Aucun code apres execve ne seras executé, sauf si
		//celui-ci fail, du coup pas de code derriere sauf un return erreur
		exit(EXIT_FAILURE);
	}
	//Dans le pere
	close(pipefd[1]);	//Plus beosin ici donc on close
	wait(NULL); //J'attend que mon ls se sois executer, sinon y a rien a lire... ^^'

	pid2 = fork();
	if (pid2 == -1)
		printf("fork error");
	if (pid2 == 0)
	{
		save[0] = dup(0);
		dup2(pipefd[0], STDIN_FILENO);
		run_command(data, cmds2);
	}

	wait(NULL);
	dup2(save[0], 0);
	close(pipefd[0]); // Je n'oublie pas de terminer de close mon pipe.
//	read(pipefd[0], buf, 200); //Je lis pipedfd[0] qui contient le fd de sortis
//	printf("buf=\n====\n%s\n====\n", buf);
}

//	char **split;
//	char **cmds;
//	int stds[1];
//	int fd;
//	int i;
//
//	i = 0;
//	split = ft_split(data->line, '|');
//	while (split[i])
//	{
//		cmds = ft_split_spec(split[i], ' ');
//		data->command = ft_strdup(cmds[0]);
//		stds[0] = dup(0);
//		fd = redirect_input();
//		run_command(data, cmds);
//		stop_redirect(fd, stds[0], STDIN_FILENO);
//		close(stds[0]);
//		free_splitted(cmds, 0);
//		free(data->command);
//		i++;
//	}