
#ifndef DEFINES_H
# define DEFINES_H

<<<<<<< HEAD
# define PRE_LINE "\x1b[38;2;232;212;98m✦ %s\033[0;0m \x1b[38;2;232;72;119m➜  \x1b[38;2;255;235;202m"
=======
# define PRE_LINE "\033[0;33m%s ➜  \033[0;0m"
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
# define COMMAND_NOT_FOUND "\033[0;31mminishell: command not found\033[0;0m"
# define ERR_COMMAND_NOT_FOUND 127
# define ARGUMENTS_ERROR "\033[0;31mminishell: arguments error\033[0;0m"
# define INVALID_FILE "\033[0;31mminishell: invalid file\033[0;0m"
# define DIR_ERROR "\033[0;31mminishell: is a directory\033[0;0m"
# define REDIRECT_MAX 1096
# define DOUBLE_AQUOTE 2
<<<<<<< HEAD
# define SIMPLE_AQUOTE 1
# define PIPE 0
# define LEFT 0
# define RIGHT 1
# define NONE -1
=======
# define LEFT_AQUOTE 3
# define SIMPLE_AQUOTE 1
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
#endif
