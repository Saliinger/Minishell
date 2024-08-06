#include "../../include/minishell.h"

void exit_shell(bool fail)
{
    if (fail == true)
        exit(EXIT_FAILURE);
    else
        exit(EXIT_SUCCESS);
}
