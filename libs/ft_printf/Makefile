# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:15:39 by llaurent          #+#    #+#              #
#    Updated: 2020/02/11 13:53:42 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= 	srcs/ft_put.c\
				srcs/ft_put2.c\
				srcs/ft_printf.c\
				srcs/handler_arg.c\
				srcs/handler_buff.c\
				srcs/handler_c.c\
				srcs/handler_diu.c\
				srcs/handler_o.c\
				srcs/handler_px.c\
				srcs/handler_s.c\
				srcs/utils.c\
				srcs/ft_strjoin_c.c
OBJS		= $(SRCSC:%.c=%.o)
NAME		= libftprintf.a
CC			= gcc
AR			= ar rc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o: ${OBJS}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@echo "\033[1;32mft_printf > Generated \033[1;33m${<:.c=.o}\033[0;0m"

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS} ${SRCSH}

all:		${NAME}

clean:
			@echo "Deleting .o files.."
			@${RM} ${OBJS}

fclean:		clean
			@echo "Deleting binary files.."
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re