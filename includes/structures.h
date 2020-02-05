
#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct	s_redirect
{
	int		start;
	int		pos;
	int		type;
	int		way;
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
	char		cwd[PATH_MAX];
	t_redirect	redirects[REDIRECT_MAX];
}				t_data;
#endif
