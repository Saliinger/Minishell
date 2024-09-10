/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:45:50 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/09 19:32:47 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	ft_close_fd(int *fd)
{
	if (*fd == -1)
		return (0);
	if (close(*fd) == -1)
		return (ft_error("error close\n", ERR_CLOSE));
	*fd = -1;
	return (0);
}
