
#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include <curses.h>
#include <term.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "get_next_line.h"
#include "defines.h"
#include "structures.h"
#include "libft.h"
#include "printf.h"

int		exec_hub(t_data *data);
int		run_command(t_data *data, char **cmds);
int		parse_line(t_data *data);
int		replace_env(t_data *data);
void	reset_redirections(t_data *data, int need_free);
t_data	*init_struct(char **env);
int		exec_env(t_data *data, char **cmds);
int		exec_pwd(t_data *data, char **cmds);
int		exec_echo(t_data *data, char **cmds);
int		exec_cd(t_data *data, char **cmds);
int		exec_unset(t_data *data, char **cmds);
int		exec_export(t_data *data, char **cmds);
int		exec_prog(t_data *data, char **cmds);
int		get_var_env(t_data *data, char *str, int *index);
int		fsp(char **splitted, char *str, int code, char *message);
int		fnr(void (*f)(void *), void *mem, int code, char *message);
int		free_splitted(char **splitted, int code);
char	**ft_split_spec(char const *s, char c);
int		tabsize(char **str);
int		quit(char *error, int code);
int		parse_arguments(t_data *data);
int		get_last_char(char *str, char c);
char	*get_env_str(t_data *data, char *temp);
int		get_next_char(char *str, char c);
void	write_preline(t_data *data);
int		remove_quotes(char **str);
int		get_redirections(t_data *data);
void	redirect(int oldfd, int newfd);
void	exec_pipeline(char ***cmds, char **env, int pos, int in_fd, t_data *data);
int     redirection_hub(t_data *data, char **cmds, int pos);
int		is_isspace(char c);
int		is_separator(char c);

#endif
