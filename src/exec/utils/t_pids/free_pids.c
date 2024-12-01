/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:20:26 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/30 00:28:26 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

/**
 * brief : frees the nodes of a t_pids list
 * 
 */
void	free_pids(t_pids **pids_adr)
{
	t_pids	*pids;
	t_pids	*tmp;

	pids = *pids_adr;
	while (pids)
	{
		tmp = pids->next;
		free(pids);
		pids = tmp;
	}
	*pids_adr = NULL;
}
