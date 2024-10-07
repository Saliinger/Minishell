/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/12 22:06:54 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*extract_command(char *line)
{
	char	*command;
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	command = (char *)malloc(sizeof(char) * (i + 1));
	if (!command)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != ' ')
	{
		command[i] = line[i];
		i++;
	}
	command[i] = '\0';
	return (command);
}

static char	*exclude(char *in)
{
	int		i;
	int		j;
	char	*trimmed;

	j = 0;
	while (in[j] && (in[j] == '\n' || in[j] == '\t' || in[j] == ' '
			|| in[j] == '\"'))
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
	char	*line;

	line = exclude(in);
	if (!line)
		return (NULL);
	if (checker_command(line, ECHO))
		return (trim(in, ECHO, true, ECHO_ID));
	else if (checker_command(line, CD))
		return (trim(in, CD, true, CD_ID));
	else if (checker_command(line, PWD))
		return (trim(in, PWD, true, PWD_ID));
	else if (checker_command(line, EXPORT))
		return (trim(in, EXPORT, true, EXPORT_ID));
	else if (checker_command(line, UNSET))
		return (trim(in, UNSET, true, UNSET_ID));
	else if (checker_command(line, ENV))
		return (trim(in, ENV, true, ENV_ID));
	else if (checker_command(line, EXIT))
		return (trim(in, EXIT, true, EXIT_ID));
	else if (checker_command(line, EXPAND))
		return (trim(in, EXPAND, true, EXPAND_ID));
	else
		return (trim(in, extract_command(line), false, -1));
}
