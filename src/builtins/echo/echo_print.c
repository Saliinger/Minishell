#include "../../../include/minishell.h"

void echo_print(char **arg, bool eof)
{
    size_t i;

    i = 0;
    while (arg[i])
    {
        printf("%s", arg[i]);
        if (arg[i + 1])
            printf(" ");
        i++;
    }
    if (eof == true)
        printf("\n");
}