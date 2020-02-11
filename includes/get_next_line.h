
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define SUCCESS 1
# define FAILURE -1
# define END 0
# define BUFFER_SIZE 64

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

int		free_string(char **str, int value);
int		ft_read_fd(int fd, char **str);
int		ft_split_str(char **str, char **line);
int		get_next_line(int fd, char **line);
int		ft_is_line(char *s);
#endif
