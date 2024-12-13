/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:03 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:28:20 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include "../../include/minishell.h"
#include "../../include/utils.h"

static int	execve_cmdpath(t_command_exec *c, t_minishell *m)
{
	int		err;
	char	*cmd_path;

	err = 0;
	cmd_path = get_cmd_path(c->cmd_args[0], m, &err);
	if (cmd_path && !err)
	{
		if (access(cmd_path, X_OK) == 0)
		{
			if (set_signals_to_default() == -1)
				return (printerr("%s: %d: err\n", __FILE__, __LINE__));
			err = execve(cmd_path, c->cmd_args, m->env);
			if (set_signals_to_ignore() == -1)
				return (printerr("%s: %d: err\n", __FILE__, __LINE__));
		}
		err = 126;
		perror("minishell");
	}
	return (err);
}

/**
 * brief : will exec the command
 * note : children either get execve'd here or get exit(-1) for failure to execve
 * if execve fails, frees everything and EXITS
 */
void	execve_command(t_command_exec *c, t_minishell *m, t_infos *i)
{
	int	exit_status;

	exit_status = 0;
	if (c->cmd_id == 0 || c->cmd_id == MINISHELL_ID)
		exit_status = execve_cmdpath(c, m);
	else if (c->cmd_id >= 1 && c->cmd_id <= 7)
		exit_status = exec_builtin(c, m, i);
	else
		printerr("%s:%d: execve error cmd_id `%s`: %d\n", __FILE__, \
									__LINE__, c->cmd_args[0], c->cmd_id);
	free_t_command_exec(&c);
	free_t_minishell(&m);
	free_t_infos(i);
	exit(exit_status);
}
