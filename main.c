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


	printf(" Column = %d | Line = %d\n", column_count, line_count);
	char* cm_cap = tgetstr("cm", NULL);
	tputs(tgoto(cm_cap, 50, 50), 1, putchar);
	while (1);
	char *reset_cmd = tgetstr("me", NULL);
	tputs(reset_cmd, 1, putchar);
}