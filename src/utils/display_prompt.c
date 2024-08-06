#include "../../include/minishell.h"

void display_prompt(void)
{
    char buffer[4096 + 1];
    char *path;

    path = getcwd(buffer, 4096);
    ft_printf("%s", path);
}