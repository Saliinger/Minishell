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

// redirection work in progress
int	check_redirection(char *in)
{
	int i = 0;
	int flag = 0;

	while (in[i])
	{
		if (flag == 0 && in[i] == '<' && in[i + 1] == '<')
		{
			while (in[i] && in[i] != ' ')
				i++;
			return (i - 1);
		}
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
