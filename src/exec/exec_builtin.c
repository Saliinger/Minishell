/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:27:56 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:18:16 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * brief : execs the builtin cmd (aka function) and returns its 
 * 											exit status if it posses one, else 0;
 * 
 */
int	exec_builtin(t_command_exec *c, t_minishell *m, t_infos *i)
{
	int	exit_status;

	(void) i;
	exit_status = 0;
	if (c->cmd_id == ECHO_ID)
		exit_status = ft_echo(c);
	else if (c->cmd_id == CD_ID)
		exit_status = ft_cd(c, m);
	else if (c->cmd_id == PWD_ID)
		exit_status = ft_pwd(m);
	else if (c->cmd_id == EXPORT_ID)
		exit_status = ft_export(c, m);
	else if (c->cmd_id == UNSET_ID)
		exit_status = ft_unset(c, m);
	else if (c->cmd_id == ENV_ID)
		exit_status = ft_env(m);
	else if (c->cmd_id == EXIT_ID)
		exit_status = ft_exit(m, c, false);
	return (exit_status);
}
