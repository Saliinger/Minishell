/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:36:28 by ekrebs            #+#    #+#             */
/*   Updated: 2023/11/29 11:06:33 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*bytes;
	unsigned char	pattern;
	size_t			i;

	bytes = s;
	i = 0;
	pattern = (unsigned char) c;
	while (i < n)
		bytes[i++] = pattern;
	return (s);
}
