/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:46:35 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/14 17:38:43 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_flag_p(const void *p, int *error)
{
	int	written;

	if (!p)
		return (ft_printf_putstr(STR_NULL_PTR, error));
	written = ft_printf_putstr("0x", error);
	written += ft_flag_x((unsigned long long) p, error);
	return (written);
}
