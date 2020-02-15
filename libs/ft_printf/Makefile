
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
AR			= ar rcs
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o: ${OBJS}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@printf "\033[2K\x1b[38;2;255;224;251mFT_PRINTF:    \x1b[38;2;250;255;175mCompilation...    \x1b[38;2;255;179;172m${<:.c=.o}\033[0;0m\r"

$(NAME):	${OBJS} | silent
			@${AR} ${NAME} ${OBJS} ${SRCSH}

silent:
			@:

all:		${NAME}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

bonus:		${NAME}

re:			fclean all

.PHONY:		all clean fclean re
