#include "../../include/minishell.h"

void    sighandler(int sig)
{
    if (sig == SIGINT)
    {
        ft_printf("\n");
        display_prompt();
        signal(SIGINT, sighandler);
    }
}
