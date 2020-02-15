#include "../../includes/minishell.h"

int		stop_redirect(int fd, int dup, int std)
{
	if ((dup2(dup, std)) < 1)
		return (-1);
	close(fd);
	return (EXIT_SUCCESS);
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

//void		redirect_input(int fd)
//{
//	struct stat	buff;
//	int			ret;

//	ret = stat("out", &buff);
//	if (ret == -1 || S_ISDIR(buff.st_mode))
//		return (EXIT_FAILURE);
//	if (!(fd = open("out", O_RDONLY)))
//		return (-1);
//	if (dup2(fd, STDIN_FILENO) < 1)
//		return (-1);
//	return (fd);
//}

int		exec_hub(t_data *data)
{

}