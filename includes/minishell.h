
#ifndef MINISHELL_H
#define MINISHELL_H

#include <libc.h>
#include <errno.h>
#include "get_next_line.h"
#include "defines.h"
#include "structures.h"
#include "libft.h"
#include "printf.h"

int		parse_line(t_data *data);
int		replace_env(t_data *data);
t_data	*init_struct(char **env);
int		get_env(t_data *data);
int		get_pwd(t_data *data);
int		get_echo(t_data *data);
int		get_cd(t_data *data);
int		get_unset(t_data *data);
int		get_export(t_data *data);
int		exec_prog(t_data *data);
int		get_var_env(t_data *data, char *str, int *index);
int		fsp(char **splitted, char *str, int code, char *message);
int		fnr(void (*f)(void *), void *mem, int code, char *message);
int		free_splitted(char **splitted, int code);
char	**ft_split_spec(char const *s, char c);
int		ft_bigstrlen(char **str);
int		quit(char *error, int code);
int		parse_arguments(t_data *data);
int		get_last_char(char *str, char c);
char	*get_env_str(t_data *data, char *temp);
int		get_next_char(char *str, char c);
void	write_preline(t_data *data);
int		remove_quotes(char **str);
#endif
