/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:38:05 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/07/27 14:46:19 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *error_msg, int errnum)
{
	if (VERBOSE >= 1)
		ft_printf("Error\nErr %d\n\t%s\n", errnum, error_msg);
	return (errnum);
}
