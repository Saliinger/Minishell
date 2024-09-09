/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:29:03 by ekrebs            #+#    #+#             */
/*   Updated: 2023/12/20 11:48:55 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_set_size(unsigned long long number, int sign)
{
	int	size;

	size = 0;
	while (number > 0)
	{
		number /= 16;
		size += 1;
	}
	if (sign < 0)
		size += 1;
	return (size);
}

static int	ft_ascii_char(int c)
{
	if (c < 10)
		return (c + '0');
	else
		return (c - 10 + 'a');
}

static char	*ft_fill_tab(char *tab, int size, unsigned long long number, \
	int sign)
{
	int	digit;

	while (number > 0)
	{
		digit = ft_ascii_char(number % 16);
		if (digit < 10)
			tab[size - 1] = (digit);
		else
			tab[size - 1] = (digit);
		number /= 16;
		size -= 1;
	}
	if (sign < 0)
		tab[0] = '-';
	return (tab);
}

char	*ft_itox(unsigned long long n, int *error)
{
	char				*tab;
	unsigned int		size;
	unsigned long long	number;
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
