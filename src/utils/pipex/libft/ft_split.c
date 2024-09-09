/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:37:29 by ekrebs            #+#    #+#             */
/*   Updated: 2023/12/04 15:39:05 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_everything(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}

//finds next [c or non c...] ([thing])
//[if on c finds next non c]
//[if on non c finds next c]
//sets i to the index of the next [thing] found
//returns 1 if done
//returns 0 if stumbled upon '\0' (end of s)
//return -42 when en of word but not end of s
static int	ft_find_next(char const *s, char const c, size_t *i)
{
	if (!s[*i])
		return (0);
	if (s[*i] == c)
	{
		*i += 1;
		while (s[*i] && s[*i] == c)
			*i += 1;
	}
	else if (s[*i] != c)
	{
		*i += 1;
		while (s[*i] && s[*i] != c)
			*i += 1;
		if (!s[*i])
			return (-42);
	}
	if (!s[*i])
		return (0);
	return (1);
}

//mallocs and gives adress of the words to the char pointers in tab
static char	**ft_split_fill_tab(char const *s, char const c, char **tab)
{
	size_t	i;
	size_t	ind_w_here;
	size_t	ind_next;

	i = 0;
	ind_next = 0;
	ind_w_here = 0;
	while (ft_find_next(s, c, &ind_next) != 0)
	{
		if (s[ind_next] != c && s[ind_next])
			ind_w_here = ind_next;
		if (s[ind_next] == c || !s[ind_next])
		{
			tab[i] = ft_substr(s, ind_w_here, ind_next - ind_w_here);
			if (!tab[i])
				return (NULL);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char const c)
{
	char	**tab;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	if (s[i] && s[i] != c)
		count++;
	while (ft_find_next(s, c, &i) > 0)
		if (s[i] && s[i] != c)
			count++;
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (ft_free_everything(tab));
	if (!ft_split_fill_tab(s, c, tab))
		return (ft_free_everything(tab));
	return (tab);
}
