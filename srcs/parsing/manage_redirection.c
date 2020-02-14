#include "../../includes/minishell.h"

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


int		exec_hub(t_data *data)
{
    (void)data;
    int pipes[2];
    int fd[2];
    pipe(pipes);

    fd[0] = dup(1);
    fd[1] = open("out", O_RDWR | O_CREAT | O_TRUNC);
    dup2(fd[1], 1);

    run_command(data, exec_prog);

    dup2(fd[0], 1);
    close(fd[0]);
    close(fd[1]);

	return (EXIT_SUCCESS);
}