/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:18:22 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/08/03 21:22:35 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	new_split(char **result, char *str, int i, int ind)
{
	int	start;

	start = i;
	i++;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			result[ind] = ft_substr(str, start, i - start + 1);
			result[ind] = ft_strtrim(result[ind], "\'");
			return (i - start + 1);
		}
		i++;
	}
	return (0);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
		{
			word++;
			i++;
			while (str[i] != '\'')
				i++;
		}
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	init_split_indexes(int *i, int *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = 0;
}

static char	**spliting(char **result, char c, char *str)
{
	int	i;
	int	j;
	int	start;

	init_split_indexes(&i, &j, &start);
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			i += new_split(result, str, i, j);
			start = i + 1;
			j++;
			if (str[i] == '\0')
				return (result[j] = NULL, result);
		}
		if (str[i] == c)
			start = i + 1;
		else if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			result[j] = ft_substr(str, start, i - start + 1);
			if (result[j++] == NULL)
				return (ft_free_tab(result), NULL);
		}
	}
	return (result[j] = NULL, result);
}

char	**ft_custom_split(char const *str, char c)
{
	char	**result;

	if (!str)
		return (NULL);
	result = ft_calloc(sizeof(char *), (count_words((char *)str, c) + 1 + 1));
	if (!result)
		return (NULL);
	result = spliting(result, c, (char *)str);
	return (result);
}
