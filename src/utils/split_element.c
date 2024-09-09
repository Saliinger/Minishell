/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/08 14:26:07 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function is to remove space between arg and not inside arg

#include "../../include/minishell.h"
#include <stdio.h>

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

static void	ft_split_write_word(char *dest, const char *src, int start, int end)
{
	int i = 0;

	printf("start: %d end: %d\n", start, end);
	while (src[start + i] && i < end)
	{
		printf("%c\n", src[start + i]);
		dest[i] = src[start + i];
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
		if (s[i] && s[i] == c)
			i++;
		else
		{
			j = 0;
			if (s[i] == '\"')
			{
				printf("1\n");
				while (s[i + j] && s[i + j] != '\"')
				{
					printf("%c\n", s[i + j]);
					j++;
				}
			}
			else if (s[i] == '\'')
			{
				printf("2\n");
				while (s[i + j] && s[i + j] != '\'')
					j++;
			}
			else if (s[i] != c)
			{
				printf("3\n");
				while(s[i + j] && s[i + j] != c)
					j++;
			}
			/*else
			{
				printf("4\n");
				while (s[i] && s[i] == c)
					i++;
			}*/
			if (j > 0)
			{
				printf("i: %zu j: %zu\n", i, j);
				dest[word] = (char *)ft_calloc(sizeof(char), (j + 1));
				if (!dest)
					return (ft_split_free(dest));
				ft_split_write_word(dest[word], s, i, j);
			}
			i += j;
			if (s[i] == '\"')
				i++;
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
	ft_print(dest, 0);
	return (dest);
}

// method
// if (str[i] == '"')
// while (str[i] && str[i] != '"') {
//  res[j] = str[i];
//	i++;
//}
// same for '
