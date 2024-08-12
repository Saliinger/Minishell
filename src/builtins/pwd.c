// display path / where i am

#include "../../include/minishell.h"

void ft_pwd(void)
{
    char *path;
    char buffer[4096 + 1];

    path = getcwd(buffer, 4096);
    printf("%s\n", path);
}
