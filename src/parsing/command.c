/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/12 19:14:08 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	if (checker_command(line, CD))
		return (trim(in, CD, true, CD_ID));
	if (checker_command(line, PWD))
		return (trim(in, PWD, true, PWD_ID));
	if (checker_command(line, EXPORT))
		return (trim(in, EXPORT, true, EXPORT_ID));
	if (checker_command(line, UNSET))
		return (trim(in, UNSET, true, UNSET_ID));
	if (checker_command(line, ENV))
		return (trim(in, ENV, true, ENV_ID));
	if (checker_command(line, EXIT))
		return (trim(in, ENV, true, EXIT_ID));
	return (trim(in, "out", false, -1));
}
