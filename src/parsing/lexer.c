// the lexer will be use to make every line uniform with char and special char 
// exemple output: 
// <<
// lol
// >
// test
// cmd1
// -opt1
// arg1
// |
// <<
// yolo
// cmd2
// -opt2
// arg2
//
// exemple input:
// <<lol
// >
// test
// cmd1
// -opt1
// arg1
// |
// <<yolo
// cmd2
// -opt2
// arg2

#include "../../include/minishell.h"

static char	**add_line(char **in, char *to_add)
{
	char **dup;
	int	lines;
	int	i;

	lines = nbr_of_line(in);
	dup = (char **)malloc(sizeof(char *) * (lines +2));
	if (!dup)
		return (NULL);
	i = 0;
	while (in[lines] && i < lines)
	{
		dup[i] = ft_strdup(in[i]);
		i++;
	}
	if (to_add)
	{
		dup[i]  = ft_strdup(to_add);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

char	*relexer(char **in)
{
	char *res;

	if (!in || !*in)
		res = NULL;

	return (res);
}
