/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimmer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/08 14:25:49 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// trim the *in and put it in the struct t_command for other use

#include "../../include/minishell.h"

t_command	*trim(char *in, char *in_command, bool builtin, int id)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->in = ft_strdup(in);
	command->arg = split_element(in, ' ');
	command->command = ft_strdup(in_command);
	command->builtin = builtin;
	command->id = id;
	command->pipe_command = NULL;
	return (command);
}

// need to add a pipe checker somewhere
// cause split element is gonna fucked everything up
// to get the pipe command just get the command
// after the pipe even if there's more than one pipe so we can loop in it
// ex :
// test "test" | grep "test" | grep "t"
// = test "test" command->pipe_command = grep "test" | grep "t"
// same for the next command
