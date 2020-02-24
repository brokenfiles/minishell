#include "../../includes/minishell.h"

int		is_isspace(char c)
{
    if ((c) && (c == '\f' || c == '\n' || c == '\v' || c == '\t' || c == '\r' || c == ' '))
        return (1);
    return (0);
}

int		is_separator(char c)
{
    if (is_isspace(c) ||  c == '>' || c == '<')
        return (1);
    return (0);
}

char    *get_last_redirect(t_data *data, char *str, int pos)
{
    int x;
    int i;
    int is_arrow;

    is_arrow = 0;
    x = 0;
    x = ft_strlen(str);
    while (--x >= 0)
    {
        if (str[x] == '>')
        {
            if (str[x - 1] && str[x - 1] == '>')
                data->redirects[pos].type = DOUBLE_AQUOTE;
            else
                data->redirects[pos].type = SIMPLE_AQUOTE;
            x += 1;
            is_arrow = 1;
            break;
        }
    }
    i = 1;
    if (is_arrow == 0)
    {
        data->redirects[pos].type = 0;
        return (ft_strdup(str));
    }
    while (str[x] && is_isspace(str[x]))
        x++;
    while (str[x + i] && !is_separator(str[x + i]))
        i++;
    return (ft_substr(str, x, i));
}

int     get_jump(char *str)
{
    int i;

    i = 0;
    while (str[i] && is_isspace(str[i]))
        i++;
    while (str[i] && !is_separator(str[i]))
        i++;
    return (i);
}

char    *remove_arrow(char *str)
{
    int x;
    char *join;
    char *sub;
    char *dup;
    int jump;
    char *tmp;

    tmp = ft_strdup(str);
    x = ft_strlen(str);
    while (--x >= 0 && str[x])
    {
        if (tmp[x] && tmp[x] == '>')
        {
            if (str[x - 1] && str[x - 1] == '>')
            {
                if (str[x - 2] && str[x - 2] == '>')
                {
                    ft_printf("minishell: parse error near '>'\n");
                    return (NULL);
                }
            }
            sub = ft_substr(tmp, 0, x - 1);
            jump = get_jump(&tmp[x + 1]);
            dup = ft_strdup(&tmp[x + 1 + jump]);
            join = ft_strjoin(sub, dup);
            free(dup);
            free(sub);
            free(tmp);
            tmp = join;
        }
    }
    return (tmp);
}

int     redirection_hub(t_data *data, char **cmds, int pos)
{
    char *temp;

    data->redirects[pos].file = get_last_redirect(data, (*cmds), pos);
    if ((temp = remove_arrow((*cmds))) == NULL)
        return (EXIT_FAILURE);
    free((*cmds));
    (*cmds) = temp;
    return (EXIT_SUCCESS);
}