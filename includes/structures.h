
#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct	s_redirect
{
	int		type;
	char	*file;
}				t_redirect;
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
	t_redirect	redirects[REDIRECT_MAX];
	int         fd[2];
	int         pipe[2];
}				t_data;
#endif
