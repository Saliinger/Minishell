/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:30 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 15:12:02 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

/**
 * brief : for each cmd in cmds,
 * will exec them as built ins if cmd has an id
 * else will exec it as an extern (execve in the child, and notes the pids in t_pids pids)
 * then waits for all the noted pids to be done and returns exit status of the last executed cmd
 * 
 * allocates & frees t_pids 
 */
int	exec_loop(t_command_exec *cmds, t_minishell *m, t_infos *i)
{
	int				err;
	int				exit_status;

	err = 0;
	err = create_all_pipes(i->cmd_count, &i->pipes);
	if (err)
		return (printerr("%s: %d: err piping.\n", __FILE__, __LINE__));			
	while (cmds)
	{
		//print_display_name(ft_itoa(cmds->index));
		//print_cmd_node(cmds, cmds->cmd_args[0]);
		err = open_cmd_fds(cmds, cmds->redir_fds);
		if (err)
			return (err);
		if (cmds->cmd_args && cmds->cmd_args[0]) // if ! cmds->cmd_args -> arrêter la chaîne d'execution ? pour l'instant on skip juste le noeud.
		{
			if (cmds->cmd_id >= 1 && cmds->cmd_id <= 7)
				exit_status = exec_builtin(cmds, m, i);
			else if(cmds->cmd_id == 0 || cmds->cmd_id == MINISHELL_ID)
				i->last_pid = exec_extern(cmds, m, i);
			else
				printerr("minishell: %s: %d: parsing error : cmd_id = %d (should have been {0,7})\n", __FILE__, __LINE__, cmds->cmd_id);
		}
		cmds = cmds->next;
	}
	return (get_exit_status(i, exit_status));
}
