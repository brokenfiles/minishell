
SRCSC		=	libs/get_next_line/get_next_line.c\
				libs/get_next_line/get_next_line_utils.c\
				srcs/minishell.c\
				srcs/parsing/parse_line.c\
				srcs/parsing/parse_arguments.c\
				srcs/structures/init_struct.c\
				srcs/exec_command/command_env.c\
				srcs/exec_command/command_pwd.c\
				srcs/exec_command/command_echo.c\
				srcs/exec_command/command_cd.c\
				srcs/exec_command/command_unset.c\
				srcs/exec_command/exec_prog.c\
				srcs/utils/errors.c\
				srcs/utils/replace_env.c\
				srcs/utils/get_env.c
OBJS		= $(SRCSC:%.c=%.o)
NAME		= minishell
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o:		${OBJS}
			@echo "\033[1;32mMinishell > Generated \033[1;33m${<:.c=.o}\033[0;0m"
			@${CC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${SRCSH}
			@make -C libs/libft
			@make -C libs/ft_printf
			@${CC} ${OBJS} ${CFLAGS} -L ./libs/libft -lft -L ./libs/ft_printf -lftprintf -o ${NAME}
			@echo "\033[1;32m┌─┐┬ ┬┌─┐┌─┐┌─┐┌─┐┌─┐"
			@echo "└─┐│ ││  │  ├┤ └─┐└─┐"
			@echo "└─┘└─┘└─┘└─┘└─┘└─┘└─┘"
			@echo "${NAME} generated successfully.\033[0;0m"

all:		${NAME}

clean:
			@make clean -C libs/libft
			@make clean -C libs/ft_printf
			@echo "\033[1;31mMinishell > Removing ${OBJS}\033[0;0m"
			@${RM} ${OBJS}

fclean:		clean
			@make fclean -C libs/libft
			@make fclean -C libs/ft_printf
			@echo "\033[1;34mMinishell > Removing ${NAME}\033[0;0m"
			@${RM} ${NAME}

re:			fclean all

rc:			re
			@make clean

%:
			@:

args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

run: ${NAME}
	@echo "\033[1;34mRunning ${NAME}...\033[0;0m"
	@echo "to build..."

bonus: ${NAME}

.PHONY:		all clean fclean re
