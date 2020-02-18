
NAME		= minishell
CC			= gcc
RM			= rm -f
OBJS_DIR	= ./objects/
HEADERS		= ./includes/
CFLAGS		= -I${HEADERS} -Wall -Wextra -Werror

SRCSC		=	libs/get_next_line/get_next_line.c\
				libs/get_next_line/get_next_line_utils.c\
				srcs/minishell.c\
				srcs/parsing/parse_line.c\
				srcs/parsing/arrow_right.c\
				srcs/parsing/parse_redirections.c\
				srcs/parsing/manage_redirection.c\
				srcs/structures/init_struct.c\
				srcs/exec_command/command_env.c\
				srcs/exec_command/command_pwd.c\
				srcs/exec_command/command_echo.c\
				srcs/exec_command/command_cd.c\
				srcs/exec_command/command_unset.c\
				srcs/exec_command/command_export.c\
				srcs/exec_command/exec_prog.c\
				srcs/utils/split_spec.c\
				srcs/utils/string_utils.c\
				srcs/utils/errors.c\
				srcs/utils/replace_env.c\
				srcs/utils/get_env.c

OBJS		= ${SRCSC:%.c=${OBJS_DIR}/%.o}

${OBJS_DIR}/%.o: %.c
			@mkdir -p ${@D}
			@printf "\033[2K\033[1;32mMinishell > Generated \033[1;33m${<:.c=.o}\033[0;0m\r"
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@make bonus -C libs/libft
			@make -C libs/ft_printf
			@${CC} ${CFLAGS} ${OBJS} -L ./libs/libft -lft -L ./libs/ft_printf -lftprintf -o ${NAME}
			@echo "\033[1;32m┌─┐┬ ┬┌─┐┌─┐┌─┐┌─┐┌─┐"
			@echo "└─┐│ ││  │  ├┤ └─┐└─┐"
			@echo "└─┘└─┘└─┘└─┘└─┘└─┘└─┘"
			@echo "${NAME} generated successfully.\033[0;0m"

run:		${NAME}
			@echo "\033[1;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

all:		${NAME}

clean:
			@make clean -C libs/libft
			@make clean -C libs/ft_printf
			@${RM} ${OBJS}

fclean:		clean
			@make fclean -C libs/libft
			@make fclean -C libs/ft_printf
			@${RM} ${NAME}

re:			fclean all

rc:			re
			@make clean

bonus:		${NAME}

.PHONY:		all clean fclean re bonus rc
