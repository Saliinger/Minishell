/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:27:56 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 03:03:57 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/**
 * brief : execs the builtin cmd (aka function) and returns its exit status if it posses one, else 0;
 * 
 */
int	exec_builtin(t_command_exec *c, t_minishell *m, t_infos *i)
{
	int	exit_status;

	i->last_cmd_type = CMD_BUILTIN;
	if (apply_redirections(c, i))
		ft_print_err("%s: %d: err applying redir\n", __FILE__, __LINE__);
	exit_status = 0;
	if (c->cmd_id == ECHO_ID)
		exit_status = ft_echo(c->cmd_args);
	else if (c->cmd_id == CD_ID)
		exit_status = ft_cd(m->env, c->cmd_args);
	else if (c->cmd_id == PWD_ID)
		exit_status = ft_pwd(m->env);
	else if (c->cmd_id == EXPORT_ID)
		exit_status = ft_export(m->env, c->cmd_args);
	else if (c->cmd_id == UNSET_ID)
		exit_status = ft_unset(m->env, c);
	else if (c->cmd_id == ENV_ID)
		exit_status = ft_env(m->env);
	else if (c->cmd_id == EXIT_ID)
		exit_status = ft_exit(m, c);
	if (restore_std_fds(m->std_fds) == -1)
		ft_print_err("%s: %d: err restore std fds", __FILE__, __LINE__);
	return (exit_status);
}
