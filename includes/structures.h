
#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct	s_redirect
{
	int		type;
	char	*file;
	struct s_redirect *next;
}				t_redirect;

typedef struct	s_pipe
{
	t_redirect *redirect;
}				t_pipe;

typedef struct	s_data
{
	int			last_return;
	char		**env;
	char		*line;
	char		*command;
	char		*arguments_line;
	char		**arguments;
	t_list		*history;
	char		cwd[PATH_MAX + 1];
	t_pipe	tPipe[REDIRECT_MAX];
	int         fd[2];
	int         pipe[2];
}				t_data;
#endif
