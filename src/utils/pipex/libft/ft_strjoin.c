/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m0rgenstern <m0rgenstern@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:16:44 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/27 02:34:43 by m0rgenstern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*failsafe(char const *s1, char const *s2)
{
	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (failsafe(s1, s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[j + i] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
