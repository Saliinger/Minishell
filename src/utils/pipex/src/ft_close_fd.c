/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:26:31 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/07/27 14:38:15 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_close_fd(int *fd)
{
	if (*fd == -1)
		return (0);
	if (close(*fd) == -1)
		return (ft_error("error close\n", ERR_CLOSE));
	*fd = -1;
	return (0);
}
