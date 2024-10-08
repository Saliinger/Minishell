/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:19:07 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/09 22:38:53 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	pids_size(t_pids *pids)
{
	t_pids	*tmp;
	int		i;

	i = 0;
	tmp = pids;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
