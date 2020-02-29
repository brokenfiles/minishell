
#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "get_next_line.h"
# include "defines.h"
# include "structures.h"
# include "libft.h"
# include "printf.h"

int			exec_hub(t_data *data);
int			run_command(t_data *data, char **cmds);
int			parse_line(t_data *data);
int			replace_env(t_data *data);
void		reset_redirections(t_data *data);
t_data		*init_struct(char **env);
int			exec_env(t_data *data, char **cmds);
int			exec_pwd(t_data *data);
int			exec_echo(char **cmds);
int			exec_cd(t_data *data, char **cmds);
int			exec_unset(t_data *data, char **cmds);
int			exec_export(t_data *data, char **cmds);
int			exec_prog(t_data *data, char **cmds, int *ret);
void		error_command_nf(char *command);
int			get_var_env(t_data *data, char *str, int *index);
int			fsp(char **splitted, char *str, int code, char *message);
int			fnr(void (*f)(void *), void *mem, int code, char *message);
int			free_splitted(char **splitted, int code);
char		**ft_split_spec(char const *s, char c);
void		handle_return(t_data *data);
int			tabsize(char **str);
int			parse_arguments(t_data *data);
int			get_last_char(char *str, char c);
int			get_first_char(char *str, char c);
int			sort_env_export(t_data *data);
int			display_export_alone(char **str);
char		*get_env(t_data *data, char *temp);
int			is_isspace(char c);
int			is_separator(char c);
int			get_jump(char *str);
t_redirect	*has_only_reg(t_redirect *begin);
int			is_built_in(char *str);
int			exec_child(char ***cmds, int pos, int in_fd, t_data *data);
int			exec_parent(char ***cmds, int pos, int in_fd, t_data *data);
int			is_pipeline(char ***cmds, int pos, int in_fd, t_data *data);
int			handle_build_in(t_data *data, int pos, int in_fd, char ***cmds);
int			is_command_alone(char ***cmds, int pos, int in_fd, t_data *data);
int			get_nb_redirect(char *str);
void		write_preline(t_data *data);
int			remove_quotes(char **str);
int			get_redirections(t_data *data);
void		redirect(int oldfd, int newfd);
int			exec_pipeline(char ***cmds, int pos, int in_fd, t_data *data);
int			redirection_hub(t_data *data, char **cmds, int pos);
int			is_isspace(char c);
int			is_separator(char c);
int			is_invalid_env(t_data *data, int x);
char		*get_first_equal(char *str);
int			is_interrogation(t_data *data, int x);
int			get_new_line(t_data *data, char *env, int index, int size);
int			get_var_env(t_data *data, char *str, int *index);
void		init_int(int *int1, int *int2, int val1, int val2);
void		ft_lstaddback_redirect(t_redirect **alst, t_redirect *new);
t_redirect	*ft_lstlast_redirect(t_redirect *lst);
t_redirect	*ft_lstnew_redirect();
void		ft_lstclear_redirect(t_redirect **lst, void (*del)(void*));
void		ft_lstaddfront_redirect(t_redirect **alst, t_redirect *new);
int			redirect_output(t_redirect *redirect);
int			handle_right_arrow(t_redirect *begin);
int			is_right_arrow(t_redirect *beggin);
int			is_left_arrow(t_redirect *beggin);
int			handle_left_arrow(t_data *data, t_redirect *begin, int is_pipeline);

#endif
