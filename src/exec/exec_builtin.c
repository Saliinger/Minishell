/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:27:56 by ekrebs            #+#    #+#             */
/*   Updated: 2024/10/23 20:08:13 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : execs the builtin cmd (aka function) and returns its exit status if it posses one, else 0;
 * 
 */
int	exec_builtin(t_command_exec *c, t_minishell *m, t_cmd_type *last_cmd_type)
{
	int	exit_status;

	*last_cmd_type = CMD_BUILTIN;
	exit_status = 0; //remember get all the existing exit_status
	/*if (c->cmd_id == ECHO_ID)
		ft_echo(m, c);
	else if (c->cmd_id == CD_ID)
		ft_cd(c, m);
	else if (c->cmd_id == PWD_ID)
		ft_pwd(m);
	else if (c->cmd_id == EXPORT_ID)
		ft_export(c, m);
	else if (c->cmd_id == UNSET_ID)
		ft_unset(c, m);
	else if (c->cmd_id == ENV_ID)
		ft_env(m);
	else if (c->cmd_id == EXIT_ID)
		exit_shell(m, c, false);*/
	(void) c;
	(void) m;
	return (exit_status);
}
