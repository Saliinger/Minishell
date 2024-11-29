#include "../../../include/minishell.h"

void echo_print(char **arg, bool eof, int i)
{
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