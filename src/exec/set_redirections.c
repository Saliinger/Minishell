/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:44:15 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 17:45:41 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * will send the content of heredoc to file descriptor fd
 * 
 * 
 */
static int send_heredoc(char *str_heredoc , int fd)
{
	ft_putstr_fd(str_heredoc, fd);
	ft_free((void **) &str_heredoc);
	return (EXIT_SUCCESS);
}

/**
 * brief : applies the redir IN and OUT from files (<infile, <<heredoc, >outfile, >>outfile_append)
 * those redirs have priority over the pipes redirs
 * 
 */
static int  apply_files_redirs(t_command_exec *cmd, int *fd_redir)
{
    int err;

    err = 0;
    if (fd_redir[IN] != -1) // am i redirected in ? 
	{
		if (fd_redir[IN] == HEREDOC)
		{
			//if (send_heredoc(cmd->last_heredoc_str, STDIN_FILENO) == -1) //fixme behbeh
			//	return(ERR_PRIM);
		}
		else if (fd_redir[IN] == R_IN_FILE)
		{
			err += ft_dup2(fd_redir[IN], STDIN_FILENO);
			err += ft_close(&fd_redir[IN]);
		}
	}
	if (fd_redir[OUT] != -1) // am i redirected out ? 
	{
		err += ft_dup2(fd_redir[OUT], STDOUT_FILENO);
		err += ft_close(&fd_redir[OUT]);
	}
    if (err)
        return (ERR_PRIM);
    return (EXIT_SUCCESS);
}

/**
 * brief : applies the redirs from the pipes
 * 
 * always redir STDIN to pipe_fds[IN]
 * if piped, will redir STDOUT to pipe_fds[OUT]
 * 
 */
static int  apply_pipe_redirs(t_command_exec *cmd, bool *am_first_cmd)
{
    int err;

	//ssi je ne suis pas le premier ?
    err = 0;
	if (*am_first_cmd != 0)
	{
		err += ft_dup2(cmd->pipe_fds[IN], STDIN_FILENO); //input from previous cmd (pipe IN)
		err += ft_close(&cmd->pipe_fds[IN]);
	}
	if (cmd->next)
	{
		err += ft_dup2(cmd->pipe_fds[OUT], STDOUT_FILENO); //output to next cmd (pipe OUT)
		err += ft_close(&cmd->pipe_fds[OUT]);
	}
    if (err)
        return (ERR_PRIM);
    return (EXIT_SUCCESS);
}

/**
 * brief : applies the redirections for the pipes and <, <<, >, >> redirections acording to the infos contained in cmd
 * files redirections (<, <<, >, >>) have priority over pipe redirections (|).
 * 
 * 
 */
static int	apply_redirections(t_command_exec *cmd, int *fds_redir, bool *am_first_cmd)
{
	int err;

    err = 0;
    err += apply_pipe_redirs(cmd, am_first_cmd);
	*am_first_cmd = false;
    err += apply_files_redirs(cmd, fds_redir);
	if (err)
		return (ERR_PRIM);
	return (EXIT_SUCCESS);
}

/**
 * brief: opens the cmd redir fds, 
 * closes everything but the last ones IN and OUT,
 * 
 * 
 */
int	set_redirections(t_command_exec *cmd, t_minishell *m, int *std_fds, bool *am_first_cmd)
{
	int	fds_redir[2];

	fds_redir[IN] = -1;
	fds_redir[OUT] = -1;
	if (open_cmd_fds(cmd, fds_redir, m) == -1) //verify & open the fds
		return (ERR);
	if (pipe(cmd->pipe_fds) == -1)
		return (perror("minishell"), ERR_PRIM);
	if (restore_std_fds(std_fds) == -1)
		return (dprintf(STDERR_FILENO, "oups\n"), ERR_PRIM);
	if (apply_redirections(cmd, fds_redir, am_first_cmd) == -1)
		return (ERR_PRIM);
	return (EXIT_SUCCESS);
}
