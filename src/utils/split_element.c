/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/09 15:37:54 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function is to remove space between arg and not inside arg

#include "../../include/minishell.h"

static void	ft_split_write_extend(size_t *i, size_t *j, const char *s, char c)
{
	*j = 0;
	if (s[*i] == '\"')
	{
		*j = 1;
		while (s[*i + *j] && s[*i + *j] != '\"')
			(*j)++;
		if (s[*i + *j] == '\"')
			(*j)++;
	}
	else if (s[*i] == '\'')
	{
		*j = 1;
		while (s[*i + *j] && s[*i + *j] != '\'')
			(*j)++;
		if (s[*i + *j] == '\'')
			(*j)++;
	}
	else if (s[*i] != c)
	{
		while (s[*i + *j] && s[*i + *j] != c)
			(*j)++;
	}
}

// the issue of the parsing is in this function it needs an update
// about the condition in the while loop for the flag
static int	ft_split_write(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		else
		{
			ft_split_write_extend(&i, &j, s, c);
			if (j > 0)
			{
				dest[word] = (char *)ft_calloc(sizeof(char), (j + 1));
				if (!dest)
					return (ft_split_free(dest));
				ft_split_write_word(dest[word], s, i, j);
			}
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
