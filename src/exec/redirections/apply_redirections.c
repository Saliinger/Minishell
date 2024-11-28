/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:44:15 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 02:58:32 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/**
 * brief : does the heredoc redir (creates a pipe, writes the heredoc in it's WRITE end, replaces the STDIN with it's READ end)
 * 
 */
int	do_heredoc_redir(t_command_exec *cmd)
{
	int	herepipe[2];
	int	err;

	ft_print_err("%s: %d: :debug: should be sent through the pipe : `%s`\n", __FILE__, __LINE__, cmd->last_heredoc_str);
	err = 0;
	err = pipe(herepipe);
	if (err)
		return (ft_print_err("%s: %d: close pipe herepipe creation failed.\n", __FILE__, __LINE__), perror("pipe herepipe creation"), ERR);
	if (cmd->last_heredoc_str)
		err = write(herepipe[WE], cmd->last_heredoc_str, ft_strlen(cmd->last_heredoc_str));
	if (err == -1)
		return (perror("write in herepipe WRITE end"), ft_close(&herepipe[WE]), ft_close(&herepipe[RE]), ERR);
	ft_free((void **) &cmd->last_heredoc_str);
	err = ft_close(&herepipe[WE]);
	if (err)
		return (perror("herepipe WRITE end"), ft_close(&herepipe[RE]), ERR);
	if (!err)
		err = ft_dup2(&herepipe[RE], STDIN_FILENO);
	if (err)
		return (perror("herepipe dup2 to STDIN"), ft_close(&herepipe[RE]), ERR);
	err = ft_close(&herepipe[RE]);
	if (err)
		return (perror("herepipe READ end"), ERR);
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
		if (fd_redir[IN] == HEREDOC_FILENO || fd_redir[IN] == HEREDOC_QUOTES_FILENO)
		{
			err = do_heredoc_redir(cmd);
		}
		else
		{
			err += ft_dup2(&fd_redir[IN], STDIN_FILENO);
			err += ft_close(&fd_redir[IN]);
		}
	}
	if (fd_redir[OUT] != -1) // am i redirected out ? 
	{
		err += ft_dup2(&fd_redir[OUT], STDOUT_FILENO);
		err += ft_close(&fd_redir[OUT]);
	}
    if (err)
        return (perror("apply files redir : unknown redir"), ERR_PRIM);
    return (EXIT_SUCCESS);
}

/**
 * 
 * brief : applies the pipes redirs.
 * 
 */
static int apply_pipes_redirs(t_command_exec *cmd, t_infos *inf)
{
	int i;
	int nb_cmds;
	int err;

	i = cmd->index;
	nb_cmds = inf->cmd_count;
	err = 0;
	if (i > 0)
	{
		err = dup2(inf->pipes[i - 1][0], STDIN_FILENO);
		if (err == -1)
			perror("pipes dup2 IN");
	}
	if (i < nb_cmds - 1)
	{
		err = dup2(inf->pipes[i][1], STDOUT_FILENO);
		if (err == -1)
			perror("pipes dup2 OUT");
	}
	err = 0;
	if (err)
		return (ft_print_err("%s: %d: err applying pipes redirs\n", __FILE__, __LINE__), ERR_PRIM);
	return (EXIT_SUCCESS);
}

/**
 * brief : applies the redirections for the pipes and <, <<, >, >> redirections acording to the infos contained in cmd
 * files redirections (<, <<, >, >>) have priority over pipe redirections (|).
 * 
 * 
 */
int	apply_redirections(t_command_exec *cmd, t_infos *i, int cmd_type)
{
	int err;

    err = 0;
	err += apply_pipes_redirs(cmd, i);
	if (err)
		perror("err applying pipes redirs");
    err += apply_files_redirs(cmd, cmd->redir_fds);
	if (err)
		return (ERR_PRIM);
	return (EXIT_SUCCESS);
}

