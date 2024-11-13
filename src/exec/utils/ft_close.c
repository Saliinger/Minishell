/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:45:50 by ekrebs            #+#    #+#             */
/*   Updated: 2024/10/21 19:35:41 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

/**
 * brief : Close the file descriptor FD.
 * 
 */
int	ft_close(int *fd)
{
	if (*fd == -1 || *fd == HEREDOC)
		return (EXIT_SUCCESS);
	if (close(*fd) == -1)
		return (perror("minishell"), ft_error("error close\n", ERR_PRIM));
	*fd = -1;
	return (EXIT_SUCCESS);
}
