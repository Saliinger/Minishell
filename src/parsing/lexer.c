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

// issue:
// <<|yolo
// need to cut it like that

#include "../../include/minishell.h"

static char	**add_line(char **in, char *to_add)
{
	printf("char to add: %s\n", to_add);
	char **dup;
	int	lines;
	int	i;

	lines = nbr_of_line(in);
	printf("lines: %d\n", lines);
	dup = (char **)malloc(sizeof(char *) * (lines + 2));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		dup[i] = ft_strdup(in[i]);
		printf("dup[%d]: %s\n",i, dup[i]);
		i++;
	}
	if (to_add)
	{
		dup[i]  = ft_strdup(to_add);
		printf("to_add: %s\n", to_add);
		i++;
	}
	dup[i] = NULL;
	printf("this is dup:\n");
	ft_print(dup, 0);
	return (dup);
}

char	**relexer(char **in)
{
	char **res;
	char *line;
	int	i;
	int	j;
	int	k;

	if (!in || !*in)
		res = NULL;
	i = 0;
	while (in[i])
	{
		printf("nbr lines res: %d\n", nbr_of_line(res));

		j = 0;
		if (in[i][j] == '<' || in[i][j] == '>')
		{
			k = 0;
			while (in[i][j] && (in[i][j] == '<' || in[i][j] == '>'))
			{
				line = ft_strjoin_frees1(line, in[i]);
				j++;
			}
						add_line(res, line);
			free(line);
			line = (char *)malloc(sizeof(char *) * (ft_strlen(in[i]) - j + 1));
			if (!line)
				return (NULL);
			while(in[i][j])
			{
				line[k] = in[i][j];
				k++;
				j++;
			}
			line[k] = '\0';
			add_line(res, line);
			free(line);
		}
		else
			add_line(res, in[i]);
		i++;
	}	
	printf("lexer out:\n");
	ft_print(res, 0);
	return (res);
}
