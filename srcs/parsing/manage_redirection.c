#include "../../includes/minishell.h"

int     is_built_in(char *str)
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
    else
        return (0);
}

int		redirect_output(t_redirect redirect)
{
    int	fd;

    if (!(fd = open(redirect.file, redirect.type == DOUBLE_AQUOTE ? O_RDWR | O_CREAT | O_APPEND
                                                                  : O_RDWR | O_CREAT | O_TRUNC, 0644)))
        return (-1);
    if (dup2(fd, STDOUT_FILENO) < 1)
        return (-1);
    return (fd);
}

void    redirect(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			close(oldfd);
	}
}

void    exec_pipeline(char ***cmds, char **env, int pos, int in_fd, t_data *data)
{
	pid_t   process;
	int     fd[2];
	int     end;

	end = 0;
	if (cmds[pos + 1] == NULL)
	{
	    if (pos > 0)
        {
            process = fork();
            if (process == 0)
            {
                redirect(in_fd, STDIN_FILENO);
                if (pos > 0)
                    close(in_fd);
                run_command(data, cmds[pos]);
                exit(EXIT_SUCCESS);
            }
        }
	    else
	    {
            if (is_built_in(cmds[pos][0]) == 0) {
                process = fork();
                if (process == 0) {
                    redirect(in_fd, STDIN_FILENO);
                    if (pos > 0)
                        close(in_fd);
                    run_command(data, cmds[pos]);
                    exit(EXIT_SUCCESS);
                }
            }
            else
                run_command(data, cmds[pos]);
        }
        if (pos > 0)
        {
            close(in_fd);
        }
	    while (end != -1)
            end = wait(NULL);
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
            close(fd[1]);
            run_command(data, cmds[pos]);
		    exit(EXIT_FAILURE);
		}
		else
		{
		    if (pos > 0)
		        close(in_fd);
            close(fd[1]);
            exec_pipeline(cmds, env, pos + 1, fd[0], data);
        }
    }

}

int		exec_hub(t_data *data)
{
	int i;
	int x;
	char ***commands;
	char **split;

	i = 0;
	split = ft_split_spec(data->line, '|');
	commands = malloc(sizeof(char**) * (tabsize(split) + 1));
	while (i < tabsize(split))
	{
        x = 0;
        if (redirection_hub(data, &split[i], i) == EXIT_FAILURE)
            return (EXIT_FAILURE);
		commands[i] = ft_split_spec(split[i], ' ');
		while (commands[i][x])
        {
		    remove_quotes(&commands[i][x]);
		    x++;
        }
		i++;
	}
	commands[i] = NULL;
	exec_pipeline(commands, data->env, 0, STDIN_FILENO, data);
	i = 0;
	while (i < tabsize(split))
	{
		free_splitted(commands[i], 0);
		i++;
	}
	free(commands);
	free_splitted(split, 0);
	return (EXIT_SUCCESS);
}