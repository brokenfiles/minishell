/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <llaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:32:25 by llaurent          #+#    #+#             */
/*   Updated: 2020/02/27 19:26:16 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_arg
{
	char	conv;
	char	flag;
	char	precision;
	char	modi;
	char	pos;
	int		w1;
	int		w2;
	int		flag_s;
}				t_arg;

int				ft_printf(const char *str, ...);
void			handle_c(char *buffer, t_arg *arg, int *count);
void			handle_u(char *buffer, t_arg *arg, int *count, int i);
void			handle_di(char *buffer, t_arg *arg, int *count, int i);
void			handle_o(char *buffer, t_arg *arg, int *count);
void			handle_p(char *buffer, t_arg *arg, int *count, int i);
void			handle_x(char *buffer, t_arg *arg, int *count, int i);
void			handle_s(char *buffer, t_arg *arg, int *count, int i);
void			padding(char c, int len, int *count);
void			handle_100(char *buffer, t_arg *arg, int *count, int i);
void			set_buff(va_list va, t_arg *arg, int *count);
int				set_arg(t_arg *arg, char *handler, va_list va);
void			handler_buff(char *buffer, t_arg *arg, int *count);
void			reset_arg(t_arg *arg);
void			ft_putchar_count(char c, int *count);
void			ft_putnbr_buff(char **buffer, int nb);
void			ft_putnbr_u_buff(char **buffer, unsigned int nb);
void			ft_putstr_count(char *str, int *count, int len);
void			ft_putstr_buff(char **buffer, char *str);
void			ft_puthexa_buff(char **buffer, long int nb, t_arg *arg,
								int flag);
void			ft_putoctal_buff(char **buffer, int nb);
void			ft_strjoin_c(char **s1, char s2);
void			ft_putchar_buff(char **buffer, int c);
#endif
