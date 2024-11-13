/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:30 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/12 15:33:43 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : for each cmd in cmds,
 * will exec them as built ins if cmd has an id
 * else will exec it as an extern (execve in the child, and notes the pids in t_pids pids)
 * then waits for all the noted pids to be done and returns exit status of the last executed cmd
 * 
 * allocates & frees t_pids 
 */
int	exec_cmds(t_command_exec *cmds, t_minishell *m, int* std_fds)
{
	int			exit_status;
	bool		am_first_cmd;
	t_cmd_type	last_cmd_type;
	t_pids_info	p;

	p.pids_list = NULL;
	am_first_cmd = true;
	while (cmds)
	{
		if (set_redirections(cmds, m, std_fds, &am_first_cmd) == -1)
			return (ERR_PRIM);
		if (cmds->cmd_args[0]) //je dois prendre en compte du type du dernier pour savoir comment récupérer son exit_status 
		{
			if (cmds->cmd_id)
				exit_status = exec_builtin(cmds, m, &last_cmd_type);
			else
				p.last_pid = exec_extern(cmds, m, &p, &last_cmd_type);
		}
		cmds = cmds->next; //free front ?
	}
	return (get_exit_status(last_cmd_type, p, exit_status));
}
