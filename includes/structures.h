
#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct	s_redirect
{
<<<<<<< HEAD
	int		start;
	int		pos;
	int		type;
	int		way;
	char	*file;
	char	*previous;
}				t_redirect;
=======
	int		type;
	char	*file;
	struct s_redirect *next;
}				t_redirect;

typedef struct	s_pipe
{
	t_redirect *redirect;
}				t_pipe;

>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
typedef struct	s_data
{
	int			last_return;
	char		**env;
	char		*line;
	char		**arguments;
	char		cwd[PATH_MAX + 1];
<<<<<<< HEAD
<<<<<<< HEAD
	t_redirect	redirects[REDIRECT_MAX];
=======
	t_pipe	tPipe[REDIRECT_MAX];
	int         fd[2];
	int         pipe[2];
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
=======
	t_pipe		tPipe[REDIRECT_MAX];
	int			fd[2];
	int			pipe[2];
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
}				t_data;
#endif
