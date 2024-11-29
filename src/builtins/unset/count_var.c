#include "../../../include/builtins.h"

int count_var(char **var)
{
    int i;

    i = 0;
    while(var[i])
        i++;
    return (i);
}
