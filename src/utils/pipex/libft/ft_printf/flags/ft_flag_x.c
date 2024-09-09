/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:55:09 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/14 17:41:40 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_flag_x(unsigned long long x, int *error)
{
	int		written;
	char	*hex;

	hex = ft_itox(x, error);
	if (*error)
		return (*error);
	written = ft_printf_putstr(hex, error);
	free(hex);
	return (written);
}
