#include "../../include/minishell.h"

void    sighandler(int sig)
{
    if (sig == SIGINT)
    {
        printf("\n");
        signal(SIGINT, sighandler);
    }
}
