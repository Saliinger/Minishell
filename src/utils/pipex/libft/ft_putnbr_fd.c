/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:08:09 by ekrebs            #+#    #+#             */
/*   Updated: 2023/12/04 18:24:35 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		digit;
	long int	num;

	if (fd < 0 || fd >= 1024)
		return ;
	num = n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	digit = '0' + num % 10;
	if (num / 10 <= 0)
	{
		ft_putchar_fd(digit, fd);
		return ;
	}
	ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(digit, fd);
	return ;
}
