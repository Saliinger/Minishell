/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cmd_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:40:53 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/14 02:38:02 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : 
 * opens the fd in t_redir *rd correctly, based on their type.
 *
 * closes them expect the last ones IN and OUT :
 * puts the opened fd of last redirection IN in fds_last_redir[IN]
 * puts the opened fd of last redirection OUT in fds_last_redir[OUT]
 * 
 */
static int	open_as_last_redir_in(t_redir *rd, int *fds_last_redir, t_command_exec *c, t_minishell *m)
{
	if (rd->type == R_IN_FILE)
	{
		if (ft_close(&fds_last_redir[IN]) == -1)
			return (ERR_PRIM);
		fds_last_redir[IN] = open(rd->redir, O_RDONLY); //maybe try access first for specific errors
		if (fds_last_redir[IN] == -1)
			return (ERR_PRIM);
	}
	else if (rd->type == R_IN_HD)
	{
		if (ft_close(&fds_last_redir[IN]) == -1)
			return (ERR_PRIM);
		fds_last_redir[IN] = HEREDOC;
		//résoudre heredoc ici ???
		ft_free((void **) &(c->last_heredoc_str));
		c->last_heredoc_str = ft_resolve_heredoc(rd->redir, m);
		//c->last_heredoc_str = rd->redir; //fixme behbeh
	}
	else
		return (perror("minishell"), dprintf(STDERR_FILENO,"minishell: in %s, %s: erreur redir in:\n\t rd->redir= `%s` \n\t rd->type=  `%d`\n", __FILE__, __FUNCTION__, rd->redir, rd->type), ERR);
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
	if (rd->type == R_OUT_FILE)
	{
		if (ft_close(&fds_last_redir[OUT]) == -1)
			return (perror("minishell"), ERR_PRIM);
		fds_last_redir[OUT] = open(rd->redir, O_WRONLY | O_CREAT, 0644); //maybe try access first for specific errors
		if (fds_last_redir[OUT] == -1)
			return (perror("minishell"), ERR_PRIM);
	}
	else if (rd->type == R_OUT_APPEND)
	{
		if (ft_close(&fds_last_redir[OUT]) == -1)
			return (perror("minishell"), ERR_PRIM);
		fds_last_redir[OUT] = open(rd->redir, O_WRONLY | O_CREAT | O_APPEND, 0644); //maybe try access first for specific errors
		if (fds_last_redir[OUT] == -1)
			
			return (perror("minishell"), ERR_PRIM);
	}
	else
		return (perror("minishell"), dprintf(STDERR_FILENO,"minishell: in %s, %s: erreur redir out:\n\t rd->redir= `%s` \n\t rd->type=  `%d`\n", __FILE__, __FUNCTION__, rd->redir, rd->type), ERR);
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
static int	open_cmd_fd(t_command_exec *c, t_redir *rd, int *fds_last_redir, t_minishell *m)
{
	t_enum_redir type;

	type = rd->type;
	if (type == R_IN_FILE || type == R_IN_HD)
	{
		dprintf(STDERR_FILENO, "beep\n");
		if (open_as_last_redir_in(rd, fds_last_redir, c, m) == -1)
			return (ERR_PRIM);
	}
	else if (type == R_OUT_FILE || type == R_OUT_APPEND)
	{
		dprintf(STDERR_FILENO, "boop\n");
		if(open_as_last_redir_out(rd, fds_last_redir) == -1)
			return (ERR_PRIM);
	}
	else
		return (dprintf(STDERR_FILENO,"minishell: in %s, %s: erreur parsing opening fd\n", __FILE__, __FUNCTION__), ERR);
	return (EXIT_SUCCESS);
}

/**
 * brief : for this cmd, opens each of its fds contained in the linked list 'cmd->redir_files_llist'
 * does it correctly, based on their type
 *
 * closes them except the last ones opened IN and OUT :
 * puts the last opened fd redirection IN in fds_last_redir[IN]
 * puts the last opened fd redirection OUT in fds_last_redir[OUT]
 */
int	open_cmd_fds(t_command_exec *cmd, int *fds_last_redir, t_minishell *m)
{
	int		err;
	int		r;
	t_redir	*rd;

	err = 0;
	rd = cmd->redir_files_llist;
	while(rd)
	{
		r = open_cmd_fd(cmd, rd, fds_last_redir, m);
		if (r)
		{
			dprintf(STDERR_FILENO, "error with redir :\n");
			print_redir(rd);
		}
		err += r;
		rd = rd->next;
	}
	if (err)
		return (dprintf(STDERR_FILENO,"minishell: in %s, %s: erreur parsing opening cmd fds\n", __FILE__, __FUNCTION__), ERR);
	return (EXIT_SUCCESS);
}
