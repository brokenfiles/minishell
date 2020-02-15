
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
				srcs/parsing/parse_redirections.c\
				srcs/parsing/parse_arguments.c\
				srcs/parsing/manage_redirection.c\
				srcs/structures/init_struct.c\
				srcs/exec_command/command_env.c\
				srcs/exec_command/command_pwd.c\
				srcs/exec_command/command_echo.c\
				srcs/exec_command/command_cd.c\
				srcs/exec_command/command_unset.c\
				srcs/exec_command/command_export.c\
				srcs/exec_command/exec_prog.c\
				srcs/utils/string_utils.c\
				srcs/utils/errors.c\
				srcs/utils/replace_env.c\
				srcs/utils/get_env.c

OBJS		= ${SRCSC:%.c=${OBJS_DIR}/%.o}

${OBJS_DIR}/%.o: %.c
			@mkdir -p ${@D}
			@printf "\033[2K\x1b[38;2;255;224;251mMINISHELL:    \x1b[38;2;250;255;175mCompilation...    \x1b[38;2;255;179;172m${<:.c=.o}\033[0;0m\r"
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	header ${OBJS}
			@printf "\033[2K\x1b[38;2;255;224;251mMINISHELL\033[0;0m:    \x1b[38;2;177;255;98mCompleted         \x1b[38;2;255;179;172m----\033[0;0m\r\n"
			@make bonus -C libs/libft
			@printf "\033[2K\x1b[38;2;255;224;251mLIBFT:        \x1b[38;2;177;255;98mCompleted         \x1b[38;2;255;179;172m----\033[0;0m\r\n"
			@make -C libs/ft_printf
			@printf "\033[2K\x1b[38;2;255;224;251mFT_PRINTF:    \x1b[38;2;177;255;98mCompleted         \x1b[38;2;255;179;172m----\033[0;0m\r"
			@${CC} ${CFLAGS} ${OBJS} -L ./libs/libft -lft -L ./libs/ft_printf -lftprintf -o ${NAME}
			@printf "\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\x1b[38;2;255;224;251mMINISHELL:    \x1b[38;2;177;255;98mReady             \x1b[38;2;255;179;172m----\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

run:		${NAME}
			@echo "\033[0;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

header:
			@printf "\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\x1b[38;2;255;224;251mNAME          \x1b[38;2;255;255;255mSTATUS            \x1b[38;2;255;179;172mFILE\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"


all:		${NAME}

clean:
			@make clean -C libs/libft
			@make clean -C libs/ft_printf
			@${RM} ${OBJS}
			@printf "\x1b[38;2;255;224;251mPROJECT:      \x1b[38;2;177;255;98mCleaned\033[0;0m\n"

fclean:		clean
			@make fclean -C libs/libft
			@make fclean -C libs/ft_printf
			@${RM} ${NAME}

re:			fclean all

bonus:		${NAME}

.PHONY:		all clean fclean re bonus rc
