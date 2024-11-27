/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:20:26 by ekrebs            #+#    #+#             */
/*   Updated: 2024/10/21 20:37:03 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

/**
 * brief : frees the nodes of a t_pids list
 * 
 */
void	free_pids(t_pids *pids)
{
	t_pids	*tmp;

	while (pids)
	{
		tmp = pids;
		pids = NULL;
		free(pids);
		pids = tmp->next;
	}
}
