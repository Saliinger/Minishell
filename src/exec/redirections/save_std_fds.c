/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_std_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:34:25 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/25 21:07:30 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

/**
 * brief : saves STDIN & STDOUT in std_fds
 * 
 */
int	save_std_fds(int *std_fds)
{
	std_fds[IN] = dup(STDIN_FILENO);
	std_fds[OUT] = dup(STDOUT_FILENO);
	if (std_fds[IN] == -1 || std_fds[OUT] == -1)
		return (perror(__FUNCTION__), ERR_PRIM);
	//print_fds(std_fds, "saved std fd", "save std fds");
	return (EXIT_SUCCESS);
}

/**
 * brief : restores the STDIN & STDOUT via dup2 according to those in std_fds
 * 
 */
int	restore_std_fds(int *std_fds)
{
	//print_fds(std_fds, "saved std fd", "restore std fds");
	if (dup2(std_fds[IN], STDIN_FILENO) == -1)
		return (perror(__FUNCTION__), ERR_PRIM);
	if (dup2(std_fds[OUT], STDOUT_FILENO) == -1)
		return (perror(__FUNCTION__), ERR_PRIM);
	return (EXIT_SUCCESS);
}

/**
 * brief: closes the fd[IN] and fd[OUT] of the int *fd[2] givent. 
 * 
 */
int	ft_close_saved_std_fds(int *std_fds)
{
	//print_fds(std_fds, "saved std fd", "close saved std fds");
	//write(STDERR_FILENO, "closed saved std fds\n", 21);
	if (ft_close(&std_fds[IN]) == -1)
	 	return (perror(__FUNCTION__), ERR_PRIM);
	if (ft_close(&std_fds[OUT]) == -1)
		return (perror(__FUNCTION__), ERR_PRIM);
	return (EXIT_SUCCESS);
}