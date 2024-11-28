/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:17:28 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 15:12:02 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/**
 * brief :  resolves this heredoc and puts it in cmd->last_heredoc_str.
 * frees cmd->last_heredoc_str and sets this heredoc instead if was already occupied.
 */
static int	resolve_heredoc(t_command_exec *cmd, t_minishell *m, t_redir *rd)
{
	int		err;
	bool	does_it_expand;

	err = 0;
	if (rd->token == REDIR_HEREDOC)
		does_it_expand = true;
	if (rd->token == REDIR_HEREDOC_MODE_IN_QUOTES)
		does_it_expand = false;
	ft_free((void **) &cmd->last_heredoc_str);
	cmd->last_heredoc_str = heredoc(rd->args, m, does_it_expand, &err);
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
	while(rd)
	{
		if (rd->token == REDIR_HEREDOC || rd->token == REDIR_HEREDOC_MODE_IN_QUOTES)
			err = resolve_heredoc(cmd, m, rd);
		if (err)
		{
			printerr("failed resolving this heredoc : \n");
			print_redir(rd);
			return (ERR);
		}
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

	if (set_signals_to_heredoc() == -1)
	 	return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	while(cmds)
	{
		err = resolve_node_heredocs(cmds, m);
		if (err)
		{
			print_cmd_node(cmds, "failed resolving this node's heredocs\n");
			return (ERR);
		}
		cmds = cmds->next;
	}
	if (set_signals_to_minishell() == -1)
	 	return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	return (EXIT_SUCCESS);
}