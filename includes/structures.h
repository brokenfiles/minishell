
#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct	s_data
{
	char	**env;
	char	*line;
	char	*command;
	char	*arguments;
	char	cwd[PATH_MAX];
}				t_data;
#endif
