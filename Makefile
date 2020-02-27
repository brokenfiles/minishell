
NAME		= minishell
CC			= gcc
RM			= rm -f
OBJS_DIR	= ./objects/
HEADERS		= ./includes/
START		= 1
CFLAGS		= -I${HEADERS} -Wall -Wextra -Werror

SRCSC		=	libs/get_next_line/get_next_line.c\
				libs/get_next_line/get_next_line_utils.c\
				srcs/minishell.c\
				srcs/parsing/parse_line.c\
				srcs/parsing/parsing_redirection.c\
				srcs/parsing/parsing_redirection2.c\
				srcs/parsing/manage_redirection.c\
				srcs/parsing/manage_redirection2.c\
				srcs/parsing/manage_redirection3.c\
				srcs/parsing/handle_redirection.c\
				srcs/parsing/handle_redirection2.c\
				srcs/structures/init_struct.c\
				srcs/exec_command/command_env.c\
				srcs/exec_command/command_pwd.c\
				srcs/exec_command/command_echo.c\
				srcs/exec_command/command_cd.c\
				srcs/exec_command/command_unset.c\
				srcs/exec_command/command_export.c\
				srcs/exec_command/command_export2.c\
				srcs/exec_command/exec_prog.c\
				srcs/utils/redirection_utils.c\
				srcs/utils/split_spec.c\
				srcs/utils/string_utils.c\
				srcs/utils/errors.c\
				srcs/utils/replace_env.c\
				srcs/utils/replace_env2.c\
				srcs/utils/utils.c\
				srcs/utils/get_env.c

OBJS		= ${SRCSC:%.c=${OBJS_DIR}/%.o}

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
			@${CC} -g -fsanitize=address ${CFLAGS} ${OBJS} -L ./libs/libft -lft -L ./libs/ft_printf -lftprintf -o ${NAME}
			@printf "\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mMINISHELL\033[0;0m:    \033[0;32mReady             \033[0;31m----          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

run:		${NAME}
			@echo "\033[0;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

header:
			@printf "\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mNAME          \033[0;0mSTATUS            \033[0;31mFILE          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

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

silent:
			@:

bonus:		${NAME}

.PHONY:		all clean fclean re bonus rc
