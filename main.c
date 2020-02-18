#include "includes/minishell.h"

int main(int argc, char **argv, char **env)
{
    struct stat	buff;
    int			fd;
    int			ret;
    pid_t       pid;
    char **cmds;
    int     stds[0];

    if (argc != 2)
        return (0);
    cmds = ft_split(argv[1], ' ');

    stds[0] = dup(0);
    ret = stat("test", &buff);
    if (ret == -1 || S_ISDIR(buff.st_mode))
        return (EXIT_FAILURE);
    if (!(fd = open("test", O_RDONLY)))
        return (-1);
    printf("slt\n");
    if (dup2(fd, STDIN_FILENO) < 1)
    {
        printf("ko dup2\n");
        return (-1);
    }
    pid = fork();
    if (pid == 0)
    {
        execve(cmds[0], cmds, env);
    }
    wait(NULL);


    if ((dup2(stds[0], STDIN_FILENO)) < 1)
        return (-1);
    close(fd);
}