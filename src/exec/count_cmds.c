/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:19:46 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 05:00:11 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	index_nodes(t_command_exec *c)
{
	int i;

	i = 0;
	while (c)
	{
		c->index = i;
		i++;
		c = c->next;
	}
}

int	count_cmds(t_command_exec *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}
