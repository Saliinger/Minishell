#include "../../../include/minishell.h"

char *add_char(char *s, char c)
{
    char *res;
    int i = 0;
    int len;

    len = ft_strlen(s);
    res = (char *) malloc(sizeof(char) * (len+ 2));
    if (!res)
        return (free(s), NULL);
    while (s[i])
    {
        res[i] = s[i];
        i++;
    }
    res[i] = c;
    res[i + 1] = '\0';
    free(s);
    return (res);
}
