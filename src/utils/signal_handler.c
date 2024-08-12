#include "../../include/minishell.h"

void    sighandler(int sig)
{
    if (sig == SIGINT)
    {
        printf("\n");
        display_prompt();
        signal(SIGINT, sighandler);
    }
}
