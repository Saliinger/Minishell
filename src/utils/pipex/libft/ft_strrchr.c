/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:11:38 by ekrebs            #+#    #+#             */
/*   Updated: 2023/11/29 11:07:48 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	pattern;
	int				i;

	pattern = (unsigned char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == pattern)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
