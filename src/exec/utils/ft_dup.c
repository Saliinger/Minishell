/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:13:47 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 08:06:16 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/**
 * brief : Duplicate FD to FD2, closing FD2 and making it open on the same file.
 * 
 * 
 */
int	ft_dup2(int fd, int fd2)
{
	int	err;

	err = dup2(fd, fd2);
	if (err == -1)
	{
		perror("minishell");
		return (ERR_PRIM);
	}
	return (EXIT_SUCCESS);
}

/**
 * brief : Duplicate FD, returning a new file descriptor on the same file.
 * 
 * 
 */
int	ft_dup(int fd)
{
	int	duped_fd;

	duped_fd = dup(fd);
	if (duped_fd == -1)
	{
		perror("minishell");
		return (ERR_PRIM);
	}
	return (duped_fd);
}
