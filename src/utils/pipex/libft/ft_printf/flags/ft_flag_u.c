/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:55:08 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/14 17:41:33 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_flag_u(unsigned int u, int *error)
{
	int		total_written;
	char	*number;

	number = ft_printf_itoa((long int) u, error);
	if (*error)
		return (0);
	total_written = ft_printf_putstr(number, error);
	free(number);
	return (total_written);
}
