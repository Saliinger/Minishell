/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:48:49 by ekrebs            #+#    #+#             */
/*   Updated: 2023/11/29 11:06:22 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*buf_src;
	unsigned char		*buf_dest;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	buf_src = src;
	buf_dest = dest;
	i = 0;
	while (i < n)
	{
		buf_dest[i] = buf_src[i];
		i++;
	}
	return (dest);
}
