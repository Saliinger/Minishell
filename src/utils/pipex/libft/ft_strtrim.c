/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:48:29 by ekrebs            #+#    #+#             */
/*   Updated: 2023/11/29 11:20:21 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_ind_start(char const *s1, char const *set)
{
	int	ind_start;
	int	moved;
	int	i;

	moved = 1;
	ind_start = 0;
	while (s1[ind_start] && moved)
	{
		moved = 0;
		i = 0;
		while (set[i])
		{
			if (s1[ind_start] == set[i])
			{
				ind_start++;
				moved = 1;
			}
			i++;
		}
	}
	return (ind_start);
}

static int	ft_find_ind_end(char const *s1, char const *set)
{
	int	ind_end;
	int	moved;
	int	i;

	ind_end = ft_strlen(s1) - 1;
	if (ind_end < 0)
		ind_end = 0;
	moved = 1;
	while (s1[ind_end] && moved)
	{
		moved = 0;
		i = 0;
		while (set[i])
		{
			if (s1[ind_end] == set[i])
			{
				ind_end--;
				moved = 1;
			}
			i++;
		}
	}
	return (ind_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		ind_start;
	int		ind_end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	ind_start = ft_find_ind_start(s1, set);
	if (s1[ind_start] == '\0')
		return (ft_strdup(""));
	ind_end = ft_find_ind_end(s1, set);
	len = ind_end - ind_start + 1;
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (ind_start + i <= ind_end)
	{
		new[i] = s1[ind_start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
