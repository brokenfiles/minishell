
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_redirect
{
	int					type;
	char				*file;
	struct s_redirect	*next;
}				t_redirect;

typedef struct	s_pipe
{
	t_redirect	*redirect;
}				t_pipe;

typedef struct	s_data
{
	int			last_return;
	int			end;
	char		**env;
	char		*line;
	char		**arguments;
	char		cwd[PATH_MAX + 1];
	pid_t		process;
	t_pipe		tpipe[REDIRECT_MAX];
	int			fd[2];
	int			pipe[2];
}				t_data;
#endif
