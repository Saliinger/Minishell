/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_extern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:27:58 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 15:03:30 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : adds the new child to known pids
 * 
 */
static int	parent(t_command_exec *c, t_pids_info *p, pid_t child_pid)
{
    (void) c;
	p->pids_list = pids_addfront(p->pids_list, child_pid);
	if (!p->pids_list)
		return (ERR);
	return (EXIT_SUCCESS);
}

/**
 * brief : exeve the command in c, with the env in m
 * 
 */
static int	child(t_command_exec *c, t_minishell *m, t_pids *pids)
{
	execve_command(c, m, pids);
	return (ERR);
}

/**
 * brief : creates a child, notes its pid in 't_pids pids', and execve the cmd in the forked child
 * returns the pid of the forked child
 * 
 * :info: the child is forced to be freed and exited at execve_command
 * 
 *  
 */
pid_t	exec_extern(t_command_exec *cmds, t_minishell *m, t_pids_info *p, t_cmd_type *last_cmd_type)
{
	pid_t	pid;

	*last_cmd_type = CMD_EXTERN;
	pid = fork();
	if (pid == -1)
		return (free_pids(p->pids_list), perror("minishell"), ERR_PRIM);
	if (pid == 0)
	{
		if (child(cmds, m, p->pids_list) == ERR)
			return (free_pids(p->pids_list), fprintf(STDERR_FILENO,"in %s: %s: at line %s child error:\n", __FILE__, __FUNCTION__, __LINE__ ), ERR_CHILD);
	}
	else
		if (parent(cmds, p, pid) == ERR)
			return (free_pids(p->pids_list), fprintf(STDERR_FILENO,"in %s: %s: at line %s parent error:\n", __FILE__, __FUNCTION__, __LINE__ ), ERR_PARENT);
	return (pid);
}
