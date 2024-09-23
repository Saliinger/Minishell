/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/23 02:47:28 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	save_fds_in_out(int *std_fds)
{
	std_fds[IN] = dup(STDIN_FILENO);
	std_fds[OUT] = dup(STDOUT_FILENO);
	if (std_fds[IN] == -1 || std_fds[OUT] == -1)
		return (perror(NULL), -1);
	return (0);
}

int	restore_fds_in_out(int *std_fds)
{
	std_fds[IN] = dup2(std_fds[IN], STDIN_FILENO);
	std_fds[OUT] = dup2(std_fds[OUT], STDOUT_FILENO);
	if (std_fds[IN] == -1 || std_fds[OUT] == -1)
		return (perror(NULL), -1);
	return (0);
}

/**
 * 
 * brief : goes to piper to executes commands of the linked list *c, gets env from *m
 * will either execute the commands via fork & execve, or execute them as built-ins
 * returns the exit status of the cmd represented by c
 * 
 * to do : resolve Heredocs ?  the heredocs need to be resolved before the forking, they are needed in the t_commands
 * to do : the signals must be reset to default at the start of ft_exec, set back to custom right after
 * 
 **/
int	ft_exec(t_command *c, t_minishell *m)
{
	int		cmd_exit_status;
	int		std_fds[2];

	cmd_exit_status = 0;
	if (!c || !c->command)
		return (ERR_ARGS); // to find out : what if exec "   " ??? => !cmds->command ???
	if (save_fds_in_out(std_fds) == -1)
		return (ERR_PRIM);
		
	cmd_exit_status = piper(c, m);

	free_t_command(&c);
	if (restore_fds_in_out(std_fds) == -1)
		return (ERR_PRIM);
	return (cmd_exit_status);
}
