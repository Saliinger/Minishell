/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:46:27 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:41:59 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"
#include "../../../include/minishell.h"

int	ft_error(char *error_msg, int errnum)
{
	if (VERBOSE >= 1)
		dprintf(STDERR_FILENO, "Error\nErr %d\n\t%s\n", errnum, error_msg);
	return (errnum);
}
