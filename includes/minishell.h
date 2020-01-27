#ifndef MINISHELL_H
#define MINISHELL_H

#include <libc.h>
#include "get_next_line.h"
#include "structures.h"
#include "defines.h"
#include "libft.h"

int		parse_line(t_data *data);
t_data	*init_struct(char **env);
int		get_env(t_data *data);
int		get_pwd(t_data *data);
int		get_echo(t_data *data);
int		get_cd(t_data *data);

#endif
