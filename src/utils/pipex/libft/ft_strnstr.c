/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:40:23 by ekrebs            #+#    #+#             */
/*   Updated: 2023/12/04 18:20:00 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	if (len == 0 && (!big || !little))
		return (NULL);
	if (!little[0])
		return ((char *) big);
	len_little = ft_strlen((const char *)little);
	i = 0;
	while (big[i] && i <= len)
	{
		if (i + len_little <= len)
		{
			if (!ft_strncmp(&big[i], little, len_little))
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
