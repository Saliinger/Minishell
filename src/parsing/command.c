/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/11 21:42:37 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	checker_command(char *in, char *command)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (in[i])
	{
		if (in[i] != command[j])
			break ;
		i++;
		j++;
	}
	if (i == ft_strlen(command))
		return (printf("command: %s\n", command), true);
	else
		return (false);
}

static char	*exclude(char *in)
{
	int		i;
	int		j;
	char	*trimmed;

	j = 0;
	while (in[j] && (in[j] == '\n' || in[j] == '\t' || in[j] == ' ' || in[j] == '\"'))
		j++;
	trimmed = (char *)malloc(sizeof(char) * ft_strlen(in + j) + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (in[j])
		trimmed[i++] = in[j++];
	trimmed[i] = '\0';
	return (trimmed);
}

bool	commands(char *in)
{
	char	*line ;

	line = exclude(in);
    printf("line: %s\n", line);
	if (!line)
		return (false);
	if (checker_command(line, ECHO))
		return (free(line), true);
	if (checker_command(line, CD))
		return (free(line), true);
	if (checker_command(line, PWD))
		return (free(line), ft_pwd(), true);
	if (checker_command(line, EXPORT))
		return (free(line), true);
	if (checker_command(line, UNSET))
		return (free(line), true);
	if (checker_command(line, ENV))
		return (free(line), true);
	return (free(line), false);
}
