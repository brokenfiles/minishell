#include "includes/minishell.h"

void	get_cursor_position(int *col, int *row)
{
	char	buff[16];
	char	*term;
	size_t	i;
	ssize_t	size;
	int		nb;

	*col = -1;
	*row = 0;
	nb = 0;
	while (nb < 20 && (*col < 0 || *row < 0))
	{
		term = tgetstr("u7", NULL);
		write(0, term, ft_strlen(term));
		if ((size = read(0, buff, 15)) < 0)
			size = 0;
		buff[size] = '\0';
		i = 2;
		*row = ft_atoi(&buff[i]) - 1;
		while (buff[i] >= '0' && buff[i] <= '9')
			i++;
		*col = ft_atoi(&buff[i + 1]) - 1;
		nb++;
	}
}

int main()
{
	char *term_type;
	term_type = getenv("TERM");

	if (tgetent(NULL, term_type) < 1)
		return (1);

	char *term;
	int col = 20;
	int row = 5;
	int colone;
	int ligne;
//	get_cursor_position(&colone, &ligne);
//	term = tgoto(tgetstr("cm", NULL), col, row);
//	write(1, term, ft_strlen(term));
	printf("Colone : %d\nLigne : %d\n", colone, ligne);
	printf("ppppp");
	write(0, "SALUT", 5);
	while (1);
}