/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:57 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/09 22:23:51 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	ft_exec(t_command *c, t_minishell *m)
{
	int		err;

	err = 0;
	if (!c || !c->command)
		return (ft_printf("Error aaargs\n"), ERR_ARGS); // what if exec "   " ??? => !cmds->command ???
	err = piper(c, m);
	free_t_command(c);
	if (err)
		return (err);
	return (0);
}
