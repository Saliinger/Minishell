#include "../../include/minishell.h"

void exit_shell(bool fail)
{
    printf("Bye Bye Bye\n");
    if (fail == true)
        exit(EXIT_FAILURE);
    else
        exit(EXIT_SUCCESS);
}
