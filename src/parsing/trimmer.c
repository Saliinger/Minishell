/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimmer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/07 22:34:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// trim the *in and put it in the struct t_command for other use

#include "../../include/minishell.h"

static char	*cut_first_cmd(char *in, int pipe_position)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * pipe_position);
	if (!res)
		return (NULL);
	while (i < pipe_position)
	{
		res[i] = in[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*remove_first_cmd(char *in, int pipe_position)
{
	char	*res;
	int		i;

	if (in[pipe_position] == '|')
		pipe_position++;
	res = (char *)malloc(sizeof(char) * ft_strlen(in + pipe_position) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (in[pipe_position])
	{
		res[i] = in[pipe_position];
		i++;
		pipe_position++;
	}
	res[i] = '\0';
	return (res);
}

// add a way to remove the first command and send it to the subcommand

t_command	*trim(char *in, char *in_command, bool builtin, int id)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->in = ft_strdup(in);
	command->pipe_position = check_pipe(in);
	if (command->pipe_position > 0)
	{
		command->pipe = true;
		command->arg = split_element(cut_first_cmd(in, command->pipe_position),
				' ');
		command->subcommand = command_init(remove_first_cmd(in,
					command->pipe_position));
	}
	else
	{
		command->subcommand = NULL;
		command->arg = split_element(in, ' ');
		ft_print(command->arg, 0);
	}
	command->command = ft_strdup(in_command);
	command->builtin = builtin;
	command->id = id;
	command->pid = -1;
	command->pipe_fds[0] = -1;
	command->pipe_fds[1] = -1;
	command->outfile_fd = -1;
	command->infile_fd = -1;
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
//
// there's a pipe checker need to trim before split element and send the rest to command without the pipe and space to create the subcommand
