/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:40:49 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/14 17:37:26 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_switch(char c, va_list l_args, int *error)
{
	if (!c || !l_args)
		return (*error = CRASH_NULL, *error);
	else if (c == 'c')
		return (ft_flag_c(va_arg(l_args, int), error));
	else if (c == 's')
		return (ft_flag_s(va_arg(l_args, const char *), error));
	else if (c == 'p')
		return (ft_flag_p(va_arg(l_args, const void *), error));
	else if (c == 'd')
		return (ft_flag_d(va_arg(l_args, int), error));
	else if (c == 'i')
		return (ft_flag_i(va_arg(l_args, int), error));
	else if (c == 'u')
		return (ft_flag_u(va_arg(l_args, unsigned int), error));
	else if (c == 'x')
		return (ft_flag_x(va_arg(l_args, unsigned int), error));
	else if (c == 'X')
		return (ft_flag_upper_x(va_arg(l_args, unsigned int), error));
	else if (c == '%')
		return (ft_flag_c('%', error));
	else
		return (ft_flag_unknown(c, error));
}

int	ft_printf(char *str, ...)
{
	int				total_written;
	int				error;
	va_list			l_args;
	size_t			i;

	error = 0;
	if (!str)
		return (error = CRASH_NULL);
	va_start(l_args, str);
	i = 0;
	total_written = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			total_written += ft_switch(str[i++ + 1], l_args, &error);
		else
			total_written += ft_printf_putchar(str[i], &error);
		if (error)
			return (va_end(l_args), ERROR_FTPRINTF);
		i++;
	}
	va_end(l_args);
	return (total_written);
}
