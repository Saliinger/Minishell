/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 17:11:09 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : saves STDIN & STDOUT in std_fds
 * 
 */
static int	save_std_fds(int *std_fds)
{
	std_fds[IN] = dup(STDIN_FILENO);
	std_fds[OUT] = dup(STDOUT_FILENO);
	if (std_fds[IN] == -1 || std_fds[OUT] == -1)
		return (perror("minishell"), ERR_PRIM);
	print_std_fds(std_fds, "SAVED STD IN(0) & OUT(1)");
	return (EXIT_SUCCESS);
}
/**
 * brief : restores the STDIN & STDOUT via dup2 according to those in std_fds
 * 
 */
int	restore_std_fds(int *std_fds)
{
	print_std_fds(std_fds, "before restore");
	if(dup2(std_fds[IN], STDIN_FILENO) == -1)
		return (perror("minishellx"), ERR_PRIM);
	if(dup2(std_fds[OUT], STDOUT_FILENO) == -1)
		return (perror("minishello"), ERR_PRIM);
	//ft_close(&std_fds[IN]);
	//ft_close(&std_fds[OUT]);
	print_std_fds(std_fds, "after restore");
	return (EXIT_SUCCESS);
}

/**
 * 
 * brief : goes to piper to executes commands of the linked list *c, gets env from *m
 * will either execute the commands via fork & execve, or execute them as built-ins
 * returns the exit status of the cmd represented by c
 * 
 * to do : resolve Heredocs ?  the heredocs need to be resolved before the forking, they are needed in the t_commands
 * to do : resolves the oppening of the in & out fds
 * to do : the signals must be reset to default at the start of ft_exec, set back to custom right after
 * 
 **/
int	ft_exec(t_command **old_t_cmd, t_minishell *m)
{
	t_command_exec	*new_t_cmd;
	int				cmd_exit_status;
	int				std_fds[2];

	std_fds[0] = -1;
	std_fds[1] = -1;
	new_t_cmd = NULL;
	if (!old_t_cmd || !m)
		return (dprintf(STDERR_FILENO,"minishell: %s: %s: parsing failure\n", __FILE__, __FUNCTION__), ERR);
	if (parsing_restruct(old_t_cmd, &new_t_cmd) <= -1)
		return (dprintf(STDERR_FILENO,"minishell: %s: %s: parsing_restruct failure\n", __FILE__, __FUNCTION__), ERR);
	if (save_std_fds(std_fds) == -1)
		return (ERR_PRIM);
	// if (set_signals_to_default() == -1)
	// 	return (ERR_PRIM);
	cmd_exit_status = 0;
	cmd_exit_status = exec_cmds(new_t_cmd, m, std_fds);
	// if (set_signals_to_minishell() == -1)
	// 	return (ERR_PRIM);
	if (restore_std_fds(std_fds) == -1)
		return (ERR_PRIM);
	free_t_command_exec(&new_t_cmd);
	printf("\nThe deed is done.\n\texit status : %d\n", cmd_exit_status);
	print_std_fds(std_fds, "at closing time");
	return (cmd_exit_status);
}
