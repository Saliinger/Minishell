/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_element_extend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:38:37 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/09 15:38:38 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	ft_countword(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0') == 1 && (s[i + 1] == '\0' || \
			s[i + 1] == c) == 0)
		{
			j++;
		}
		i++;
	}
	return (j);
}

int	ft_split_free(char **dest)
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

void	ft_split_write_word(char *dest, const char *src, int start, int end)
{
	int	i;

	i = 0;
	while (src[start + i] && i < end)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
}
