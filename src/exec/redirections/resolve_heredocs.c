/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:17:28 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:37:17 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

/**
 * brief :  resolves this heredoc and puts it in cmd->last_heredoc_str.
 * frees cmd->last_heredoc_str and sets this heredoc
 * 											 instead if was already occupied.
 */
static int	resolve_heredoc(t_command_exec *cmd, t_minishell *m, t_redir *rd)
{
	int		err;

	err = 0;
	ft_free((void **) &cmd->last_heredoc_str);
	cmd->last_heredoc_str = heredoc(rd->redir, m);
	if (err)
		return (ERR);
	return (EXIT_SUCCESS);
}

/**
 * brief : for each redir node in cmd, resolves it's heredocs.
 * the last one is put in cmd->last_heredoc_str.
 */
static int	resolve_node_heredocs(t_command_exec *cmd, t_minishell *m)
{
	int		err;
	t_redir	*rd;

	rd = cmd->redir_files_llist;
	err = 0;
	while (rd)
	{
		if (rd->type == R_IN_HEREDOC || rd->type == R_IN_HEREDOC_Q)
			err = resolve_heredoc(cmd, m, rd);
		if (err)
			return (printerr("failed resolving a heredoc.\n"), ERR);
		rd = rd->next;
	}
	return (EXIT_SUCCESS);
}

/**
 * brief : for each node in cmd, resolves all it's heredocs, 
 * and puts it's last str in cmd->last_heredoc_str
 * 
 */
int	resolve_all_heredocs(t_command_exec *cmds, t_minishell *m)
{
	int		err;

	while (cmds)
	{
		err = resolve_node_heredocs(cmds, m);
		if (err)
			return (printerr("failed resolving this cmd %d's heredocs\n", \
															cmds->index), ERR);
		cmds = cmds->next;
	}
	return (EXIT_SUCCESS);
}
