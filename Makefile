
NAME		= minishell
CC			= gcc
RM			= rm -f
OBJS_DIR	= ./objects/
HEADERS		= ./includes/
<<<<<<< HEAD
=======
START		= 1
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
CFLAGS		= -I${HEADERS} -Wall -Wextra -Werror

SRCSC		=	libs/get_next_line/get_next_line.c\
				libs/get_next_line/get_next_line_utils.c\
				srcs/minishell.c\
				srcs/parsing/parse_line.c\
<<<<<<< HEAD
<<<<<<< HEAD
				srcs/parsing/parse_redirections.c\
				srcs/parsing/parse_arguments.c\
				srcs/parsing/manage_redirection.c\
=======
				srcs/parsing/arrow_right.c\
=======
				srcs/parsing/parsing_redirection.c\
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
				srcs/parsing/manage_redirection.c\
				srcs/parsing/handle_redirection.c\
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
				srcs/structures/init_struct.c\
				srcs/exec_command/command_env.c\
				srcs/exec_command/command_pwd.c\
				srcs/exec_command/command_echo.c\
				srcs/exec_command/command_cd.c\
				srcs/exec_command/command_unset.c\
				srcs/exec_command/command_export.c\
				srcs/exec_command/command_export2.c\
				srcs/exec_command/exec_prog.c\
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
				srcs/utils/redirection_utils.c\
>>>>>>> 586c70967af1505838861dbb3ab967e8f7b9a799
				srcs/utils/split_spec.c\
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
				srcs/utils/string_utils.c\
				srcs/utils/errors.c\
				srcs/utils/replace_env.c\
				srcs/utils/replace_env2.c\
				srcs/utils/utils.c\
				srcs/utils/get_env.c

OBJS		= ${SRCSC:%.c=${OBJS_DIR}/%.o}
<<<<<<< HEAD

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
=======

${OBJS_DIR}/%.o: %.c
			@mkdir -p ${@D}
			@printf "\033[2K\033[0;35mMINISHELL\033[0;0m:    \033[0;33mCompilation...    \033[0;31m%-15.15s\033[0;0m\r" $(notdir ${<})
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	header ${OBJS}
			@printf "\033[2K\033[0;35mMINISHELL\033[0;0m:    \033[0;32mCompleted         \033[0;31m----\033[0;0m          \r\n"
			@make bonus -C libs/libft
			@printf "\033[2K\033[0;35mLIBFT\033[0;0m:        \033[0;32mCompleted         \033[0;31m----\033[0;0m          \r\n"
			@make -C libs/ft_printf
			@printf "\033[2K\033[0;35mFT_PRINTF\033[0;0m:    \033[0;32mCompleted         \033[0;31m----\033[0;0m          \r"
			@${CC} ${CFLAGS} ${OBJS} -L ./libs/libft -lft -L ./libs/ft_printf -lftprintf -o ${NAME}
			@printf "\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mMINISHELL\033[0;0m:    \033[0;32mReady             \033[0;31m----          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

run:		${NAME}
			@echo "\033[0;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

header:
			@printf "\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mNAME          \033[0;0mSTATUS            \033[0;31mFILE          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7

run:		${NAME}
			@echo "\033[1;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

all:		${NAME}

clean:
			@make clean -C libs/libft
			@make clean -C libs/ft_printf
			@${RM} ${OBJS}
			@printf "\033[0;35mPROJECT\033[0;0m:      \033[0;32mCleaned\033[0;0m\n"

fclean:		clean
			@make fclean -C libs/libft
			@make fclean -C libs/ft_printf
			@${RM} ${NAME}

re:			fclean all

<<<<<<< HEAD
rc:			re
			@make clean
=======
silent:
			@:
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7

bonus:		${NAME}

.PHONY:		all clean fclean re bonus rc
