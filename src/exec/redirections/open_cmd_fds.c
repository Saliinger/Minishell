/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cmd_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:40:53 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 20:33:49 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"
//#include "prompt.h"

/**
 * brief : 
 * opens the fd in t_redir *rd correctly, based on their type.
 *
 * closes them expect the last ones IN and OUT :
 * puts the opened fd of last redirection IN in fds_last_redir[IN]
 * puts the opened fd of last redirection OUT in fds_last_redir[OUT]
 * 
 */
static int	open_as_last_redir_in(t_redir *rd, int *fds_last_redir)
{
	if (rd->type == R_IN_FILE)
	{
		if (ft_close(&fds_last_redir[IN]) == -1)
			return (ERR_PRIM);
		fds_last_redir[IN] = open(rd->redir, O_RDONLY);
		if (fds_last_redir[IN] == -1)
			return (ERR_PRIM);
	}
	else if (rd->type == R_IN_HEREDOC || rd->type == R_IN_HEREDOC_Q)
	{
		if (ft_close(&fds_last_redir[IN]) == -1)
			return (ERR_PRIM);
		if (rd->type == R_IN_HEREDOC)
			fds_last_redir[IN] = HEREDOC_FILENO;
		else if (rd->type == R_IN_HEREDOC_Q)
			fds_last_redir[IN] = HEREDOC_QUOTES_FILENO;
	}
	else
		return (printerr("minishell: in %s, %s: err opening redir fds in\n", \
												__FILE__, __FUNCTION__), ERR);
	return (EXIT_SUCCESS);
}

/**
 * brief : 
 * opens the fd in t_redir *rd correctly, based on their type.
 *
 * closes them expect the last ones IN and OUT :
 * puts the opened fd of last redirection IN in fds_last_redir[IN]
 * puts the opened fd of last redirection OUT in fds_last_redir[OUT]
 * 
 */
static int	open_as_last_redir_out(t_redir *rd, int *fds_last_redir)
{
	if (rd->type == R_OUT_FILE_TRUNC)
	{
		if (ft_close(&fds_last_redir[OUT]) == -1)
			return (ERR_PRIM);
		fds_last_redir[OUT] = open(rd->redir, O_WRONLY \
												| O_CREAT | O_TRUNC, 0644);
		if (fds_last_redir[OUT] == -1)
			return (ERR_PRIM);
	}
	else if (rd->type == R_OUT_FILE_APPEND)
	{
		if (ft_close(&fds_last_redir[OUT]) == -1)
			return (ERR_PRIM);
		fds_last_redir[OUT] = open(rd->redir, O_WRONLY \
												| O_CREAT | O_APPEND, 0644);
		if (fds_last_redir[OUT] == -1)
			return (ERR_PRIM);
	}
	else
		return (printerr("minishell: in %s, %s: err open redir fds out\n", \
												__FILE__, __FUNCTION__), ERR);
	return (EXIT_SUCCESS);
}

/**
 * brief : 
 * opens the fd in t_redir *rd correctly, based on their type.
 *
 * closes them expect the last ones IN and OUT :
 * puts the opened fd of last redirection IN in fds_last_redir[IN]
 * puts the opened fd of last redirection OUT in fds_last_redir[OUT]
 * 
 */
static int	open_cmd_fd(t_redir *rd, int *fds_last_redir)
{
	int	type;

	type = rd->type;
	if (type == ERR)
		return (printerr("minishell: %s: err redirect\n", rd->redir), 1);
	else if (type == R_IN_FILE || type == R_IN_HEREDOC \
													|| type == R_IN_HEREDOC_Q)
	{
		if (open_as_last_redir_in(rd, fds_last_redir) == -1)
			return (ERR_PRIM);
	}
	else if (type == R_OUT_FILE_TRUNC || type == R_OUT_FILE_APPEND)
	{
		if (open_as_last_redir_out(rd, fds_last_redir) == -1)
			return (ERR_PRIM);
	}
	else
		return (printerr("minishell: in %s, %s: err open redir fds type\n", \
												__FILE__, __FUNCTION__), ERR);
	return (EXIT_SUCCESS);
}

//cat <pd >am_i_created_now <ill
/**
 * brief : for this cmd, opens each of its fds contained in the 
 * 												linked list c->redirection
 * does it correctly, based on their type. stops at the first bad redir 
 * 										(illegal path or permission denied).
 *
 * closes them except the last ones opened IN and OUT :
 * puts the last opened fd redirection IN in fds_last_redir[IN]
 * puts the last opened fd redirection OUT in fds_last_redir[OUT]
 * 
 * :note: if `No such file or directory` || `permission denied`, 
 * 													says it and returns 1 
 */
int	open_cmd_fds(t_command_exec *cmd, int *fds_last_redir)
{
	int		err;
	t_redir	*rd;

	rd = cmd->redir_files_llist;
	while (rd)
	{
		err = open_cmd_fd(rd, fds_last_redir);
		if (err)
		{
			if (err != 1)
			{
				printerr("minishell: ");
				perror(rd->redir);
			}
			return (1);
		}
		rd = rd->next;
	}
	return (EXIT_SUCCESS);
}
