/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restruct_discarding_old.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:31:01 by ekrebs            #+#    #+#             */
/*   Updated: 2024/10/23 14:28:38 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

/**
 * brief : frees the boat data from old (we don't need it), sets the addr to NULL, 
 * 
 * 
 */
static void	ft_free_old_bloat_datas(t_command *old)
{
	ft_free((void **) &old->in);
	ft_free((void **) &old->command);
	ft_free_nullterm_tab(&old->arg);
}
/**
 * brief : for each node in old: frees the bloat data fields, then frees the node. sets o to NULL.
 * 
 */
void	restruct_discarding_old(t_command **o)
{
	t_command *old;
	t_command *tmp;

	if (!o || !*o)
		return ;
	old = *o;
	while (old)
	{
		tmp = old->subcommand;
		ft_free_old_bloat_datas(old);
		ft_free((void **) old);
		old = tmp;
	}
	*o = NULL;
	return ;
}
