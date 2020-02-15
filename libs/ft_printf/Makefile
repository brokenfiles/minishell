
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
			@printf "\033[2K\033[1;32mft_printf > Generated \033[1;33m${<:.c=.o}\033[0;0m\r"

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
