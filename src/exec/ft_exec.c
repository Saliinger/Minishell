/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:14:31 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/29 03:03:25 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include "../../include/minishell.h"

int	init_t_infos(t_command_exec *cmds, t_infos *i)
{
	i->pids_llist = NULL;
	i->last_pid = -1;
	i->last_cmd_type = -1;
	i->cmd_count = count_cmds(cmds);
	i->pipes = NULL;
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
int	ft_exec(t_command **old, t_minishell *m)
{
	int				cmd_exit_status;
	t_command_exec	*new;
	t_infos			i;

	cmd_exit_status = 0;
	parsing_restruct(old, &new);
	if (init_t_infos(new, &i))
		return (printerr("%s: %d: error: failed reparsing", __FILE__, __LINE__), ERR_PRIM);
	if (resolve_all_heredocs(new, m) != 0)
		return (print_cmd_node(new, "err resolving heredocs"), printerr("%s: %d: error resovling the heredocs", __FILE__, __LINE__), ERR);
	//print_cmd_nodes(new, "resolved heredocs");
	cmd_exit_status = exec_loop(new, m, &i);
	//free_t_infos(&i);
	free_t_command_exec(&new);
	if (set_signals_to_minishell() == -1)
		return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	if (restore_std_fds(m->std_fds) == -1)
		return (ERR_PRIM);
	return (cmd_exit_status);
}
