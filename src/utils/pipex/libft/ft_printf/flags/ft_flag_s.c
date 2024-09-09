/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:23:32 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/14 17:38:55 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_flag_s(const char *s, int *error)
{
	int	written;

	if (!s)
		return (ft_printf_putstr("(null)", error));
	written = ft_printf_putstr(s, error);
	return (written);
}
