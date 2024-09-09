/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fds_io.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m0rgenstern <m0rgenstern@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:19:04 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/07/27 01:56:23 by m0rgenstern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_close_fds_io(t_pipex *p)
{
	if (close(p->fds.outfile) == ERR_CLOSE)
		return (ft_error("close(p->fds.infile)\n", ERR_CLOSE));
	if (close(p->fds.outfile) == ERR_CLOSE)
		return (ft_error("close(p->fds.outfile)\n", ERR_CLOSE));
	return (0);
}
