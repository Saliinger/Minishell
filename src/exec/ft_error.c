/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:46:27 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/09 19:36:49 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	ft_error(char *error_msg, int errnum)
{
	if (VERBOSE >= 1)
		ft_printf_fd(STDERR_FILENO, "Error\nErr %d\n\t%s\n", errnum, error_msg);
	return (errnum);
}
