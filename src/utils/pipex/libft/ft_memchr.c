/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:40:55 by ekrebs            #+#    #+#             */
/*   Updated: 2023/11/29 11:05:56 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buf_bytes;
	unsigned char	pattern;
	size_t			i;

	pattern = (unsigned char) c;
	buf_bytes = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (buf_bytes[i] == pattern)
			return (&buf_bytes[i]);
		i++;
	}
	return (NULL);
}
