/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/12 17:12:06 by anoukan          ###   ########.fr       */
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

t_command	*command_init(char *in)
{
	char	*line ;

	line = exclude(in);
	if (!line)
		return (NULL);
	if (checker_command(line, ECHO))
		return (trim(in, ECHO));
	if (checker_command(line, CD))
		return (trim(in, CD));
	if (checker_command(line, PWD))
		return (trim(in, PWD));
	if (checker_command(line, EXPORT))
		return (trim(in, EXPORT));
	if (checker_command(line, UNSET))
		return (trim(in, UNSET));
	if (checker_command(line, ENV))
		return (trim(in, ENV));
	return (NULL);
}
