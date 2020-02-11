#include "includes/minishell.h"

int main()
{
	char *term_type;
	term_type = getenv("TERM");

	if (tgetent(NULL, term_type) < 1)
	{
		printf("Can't use tgetent\n");
		return (1);
	}
	int column_count;
	column_count = tgetnum("co");
	int line_count;
	line_count = tgetnum("li");

	char *line;
	printf(" Column = %d | Line = %d\n", column_count, line_count);;
	tputs(tgetstr("cr", 0), STDIN_FILENO, &putchar);
	printf("WOOOOOOOOOOOOOOOOOOOW\n");
	get_next_line(0, &line);
	char *reset_cmd = tgetstr("me", NULL);
	tputs(reset_cmd, 1, putchar);
}