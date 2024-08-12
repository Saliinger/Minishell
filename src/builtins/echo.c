// echo command + option -n
// carefull with space and multiple time the same option

#include "../../include/minishell.h"
#include <stdio.h>

static int	flag(char *str)
{
	int i = 0;
	int flag = 0;

	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == 'n')
			flag++;
		i++;
	}
	return (flag);
}

void	ft_echo(t_command *command)
{
	if (flag(command->in) > 0)
		printf("%s\n", command->in);
	else
		printf("%s", command->in);
}
