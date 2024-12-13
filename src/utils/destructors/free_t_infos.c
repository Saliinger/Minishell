/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 05:55:45 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:59:00 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/**
 * 
 * brief : frees the struct's data fields
 * 
 * 
 */
void	free_t_infos(t_infos *i)
{
	free_pids(&i->pids_llist);
	ft_close_pipes(i->cmd_count - 1, &i->pipes);
}
