/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:05:17 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/03 14:56:44 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_set_size(unsigned long int number, int sign)
{
	int	size;

	size = 0;
	while (number > 0)
	{
		number /= 10;
		size += 1;
	}
	if (sign < 0)
		size += 1;
	return (size);
}

static char	*ft_fill_tab(char *tab, int size, unsigned long int number, \
	int sign)
{
	while (number > 0)
	{
		tab[size - 1] = ('0' + number % 10);
		number /= 10;
		size -= 1;
	}
	if (sign < 0)
		tab[0] = '-';
	return (tab);
}

char	*ft_printf_itoa(long int n, int *error)
{
	char				*tab;
	size_t				size;
	unsigned long int	number;
	int					sign;

	size = 0;
	sign = 1;
	if (n <= 0)
		sign *= -1;
	number = n * sign;
	size = ft_set_size(number, sign);
	tab = malloc((size + 1) * sizeof(char));
	if (!tab)
		return (*error = CRASH_MALLOC, NULL);
	tab[size] = '\0';
	tab = ft_fill_tab(tab, size, number, sign);
	if (number == 0)
		tab[0] = '0';
	return (tab);
}
