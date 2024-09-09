/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:58:09 by ekrebs            #+#    #+#             */
/*   Updated: 2023/11/29 11:07:05 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	pattern;
	size_t			i;

	pattern = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == pattern)
			return ((char *) &s[i]);
		i++;
	}
	if (pattern == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
