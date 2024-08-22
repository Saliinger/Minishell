// display path / where i am

#include "../../include/minishell.h"
#include <stdio.h>

void	ft_pwd(t_minishell *minishell)
{
	printf("%s\n", minishell->pwd);
}
