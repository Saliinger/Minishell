/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:31:52 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function is to remove space between arg and not inside arg

#include "../../include/minishell.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0') == 1 && (s[i + 1] == '\0' || s[i
				+ 1] == c) == 0)
		{
			j++;
		}
		i++;
	}
	return (j);
}

static int	ft_split_free(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (0);
}

static void	ft_split_write_word(char *dest, const char *src, char c)
{
	size_t	i;
	size_t	flag;

	i = 0;
	while (src[i] && src[i] != c)
	{
		flag = 0;
		if (src[i] == 34 || src[i] == 39)
		{
			flag = 1;
			while (flag == 1)
			{
				dest[i] = src[i];
				if (src[i] == 34 || src[i] == 39)
					flag = 0;
				if (flag == 1)
					i++;
			}
		}
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

// the issue of the parsing is in this function it needs an update
// about the condition in the while loop for the flag
static int	ft_split_write(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;
	size_t	flag;

	word = 0;
	i = 0;
	while (s[i])
	{
		flag = 0;
		if ((s[i] == c || s[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((s[i + j] == c || s[i + j] == '\0') == 0)
				j++;
			dest[word] = (char *)ft_calloc(sizeof(char), (j + 1));
			if (!dest)
				return (ft_split_free(dest));
			ft_split_write_word(dest[word], (char *)(s + i), c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**split_element(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = ft_calloc(sizeof(char *), (ft_countword(s, c) + 1));
	if (!dest)
		return (NULL);
	ft_split_write(dest, s, c);
	return (dest);
}
