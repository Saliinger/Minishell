/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:47:05 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*extract_command(char *line)
{
	char	*command;
	int		i;
    int     j;

	i = 0;
    while(line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
        i++;
    if (!line[i])
        return (NULL);
    j = 0;
    while (line[i + j] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
        j++;
    command = (char *)malloc(sizeof(char) * j + 1);
    if (!command)
        return (NULL);
    ft_strlcpy(command, line + i, j);
	return (command);
}

t_command	*command_init(char *in)
{
	char	*line;

	line = extract_command(in);
	if (!line)
		return (free(in), NULL);
	if (checker_command(line, ECHO))
		return ( free(line), trim(in, ECHO, true, ECHO_ID));
	else if (checker_command(line, CD))
		return ( free(line), trim(in, CD, true, CD_ID));
	else if (checker_command(line, PWD))
		return ( free(line), trim(in, PWD, true, PWD_ID));
	else if (checker_command(line, EXPORT))
		return ( free(line), trim(in, EXPORT, true, EXPORT_ID));
	else if (checker_command(line, UNSET))
		return ( free(line), trim(in, UNSET, true, UNSET_ID));
	else if (checker_command(line, ENV))
		return (free(line),  trim(in, ENV, true, ENV_ID));
	else if (checker_command(line, EXIT))
		return ( free(line), trim(in, EXIT, true, EXIT_ID));
	else
		return (trim(in, line, false, -1));
}
