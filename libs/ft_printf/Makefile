
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
<<<<<<< HEAD
			@printf "\033[2K\033[1;32mft_printf > Generated \033[1;33m${<:.c=.o}\033[0;0m\r"
=======
			@printf "\033[2K\033[0;35mFT_PRINTF\033[0;0m:    \033[0;33mCompilation...    \033[0;31m%-15.15s\033[0;0m\r" $(notdir ${<})
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7

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
