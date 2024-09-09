/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:11:42 by ekrebs            #+#    #+#             */
/*   Updated: 2024/06/28 19:01:15 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strdup(const char *s)
{
	char	*new_s;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_gnl_strlen(s) + 1;
	new_s = malloc (size);
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

int	ft_ind_strchr(const char *s, int c)
{
	unsigned char	pattern;
	size_t			i;

	if (!s)
		return (-1);
	pattern = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == pattern)
			return (i);
		i++;
	}
	if (pattern == '\0')
		return (i);
	return (-1);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
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

void	*ft_gnl_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*bytes_dest;
	const unsigned char	*bytes_src;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	bytes_dest = dest;
	bytes_src = src;
	i = 0;
	if (bytes_src >= bytes_dest)
	{
		while (i < n)
		{
			bytes_dest[i] = bytes_src[i];
			i++;
		}
	}
	else
	{
		while (i++ < n)
		{
			bytes_dest[n - i] = bytes_src[n - i];
		}
	}
	return (dest);
}
