/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:54:50 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/25 16:09:23 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_printf_putstr(const char *str, int *error)
{
	int	written;
	int	len_str;

	if (!str)
		return (*error = CRASH_NULL);
	len_str = ft_printf_strlen(str, error);
	written = write(2, str, len_str);
	if (written < len_str)
		*error = CRASH_WRITE;
	return (written);
}
