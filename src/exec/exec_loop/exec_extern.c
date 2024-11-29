/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_extern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:27:58 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/29 04:09:59 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

/**
 * brief : adds the new child to known pids
 * 
 */
static int	parent(t_command_exec *cmd, t_infos *i, pid_t child_pid)
{
	if (cmd->cmd_id == MINISHELL_ID)
		if (set_signals_to_ignore() == -1)
			return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	i->pids_llist = pids_addfront(i->pids_llist, child_pid);
	if (!i->pids_llist)
		return (ERR);
	return (EXIT_SUCCESS);
}

/**
 * brief : exeve the command in c, with the env in m
 * 
 */
static int	child(t_command_exec *c, t_minishell *m, t_infos *inf)
{
	int err;

	err = 0;
	err += ft_close_saved_std_fds(m->std_fds);
	if (err)
		return(printerr("%s: %d: err closing the std fds\n", __FILE__, __LINE__), ERR);
	err += apply_redirections(c, inf);
	err += ft_close_pipes(inf->cmd_count -1, &inf->pipes);
	if (err)
		return(printerr("%s: %d: err redir\n", __FILE__, __LINE__), ERR);
	execve_command(c, m, inf);
	return (printerr("%s: err What the hell have you done ?\n", __FUNCTION__));
}

/**
 * brief : creates a child, notes its pid in 't_pids pids', and execve the cmd in the forked child
 * returns the pid of the forked child
 * 
 * :info: the child is forced to be freed and exited at execve_command
 * 
 *  
 */
pid_t	exec_extern(t_command_exec *cmd, t_minishell *m, t_infos *inf)
{
	pid_t	pid;

	inf->last_cmd_type = CMD_EXTERN;
	pid = fork();
	if (pid == -1)
		return (free_pids(inf->pids_llist), perror("minishell00"), ERR_PRIM);
	if (pid == 0)
	{
		if (child(cmd, m, inf) == ERR)
			return (free_pids(inf->pids_llist), printerr("in %s: %s: child error:\n", __FILE__, __FUNCTION__ ), ERR);
	}
	else if (parent(cmd, inf, pid) == ERR)
			return (free_pids(inf->pids_llist), printerr("in %s: %s: parent error:\n", __FILE__, __FUNCTION__ ), ERR);
	return (pid);
}