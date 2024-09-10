/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids_addfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:20:22 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/09 22:39:27 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

/**
 * brief : adds a node to the front of a t_pid lst, containing pid
 * if pids NULL, creates and returns a node containing pid, 
 * the lst is NULL terminated
 * 
 */
t_pids	*pids_addfront(t_pids *pids, pid_t pid)
{
	t_pids	*new;

	new = malloc(sizeof(struct s_pids));
	if (!new)
		return (NULL);
	new->pid = pid;
	if (!pids)
	{
		new->next = NULL;
		return (new);
	}
	new->next = pids;
	return (new);
}
