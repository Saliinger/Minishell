/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:14:31 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 08:52:23 by ekrebs           ###   ########.fr       */
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
 * brief : goes to piper to executes commands of the linked list *c, 
 * gets env from *m
 * 
 * will either execute the extern commands or pipelines via fork & execve, 
 * or execute the solo built-ins as functions.
 * 
 * returns the exit status of the cmd represented by c
 * 
 * 
 **/
int	ft_exec(t_command **old, t_minishell *m)
{
	int				exit_status;
	t_command_exec	*new;
	t_infos			i;

	parsing_restruct(old, &new);
	if (init_t_infos(new, &i))
		return (printerr("%s: %d: error: failed reparsing", \
											__FILE__, __LINE__), ERR_PRIM);
	if (resolve_all_heredocs(new, m) != EXIT_SUCCESS)
		return (print_cmd_node(new, "err resolving heredocs"), \
					printerr("%s: %d: error resovling the heredocs", \
													__FILE__, __LINE__), ERR);
	print_cmd_nodes(new, "resolved heredocs");
	if (create_all_pipes(i.cmd_count, &i.pipes) != EXIT_SUCCESS)
		return (printerr("%s: %d: err piping.\n", __FILE__, __LINE__));
	exit_status = exec_loop(&new, m, &i);
	if (restore_std_fds(m->std_fds) == -1)
		return (ERR_PRIM);
	return (exit_status);
}
