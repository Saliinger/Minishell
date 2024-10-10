#include "../../include/minishell.h"

int	check_pipe(char *in)
{
	int i = 0;
	int flag = 0;

	while (in[i])
	{
		if (flag == 0 && in[i] == '|')
			return (i);
		if (in[i] == '"')
		{
			while (in[i] != '"')
				i++;
		}
		if (in[i] == '\'')
		{
			while (in[i] != '\'')
				i++;
		}
		i++;
	}
	return (0);
}
