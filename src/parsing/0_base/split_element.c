/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:52:53 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_split_write_extend(size_t *i, size_t *j, const char *s, char c)
{
    *j = 0;
    while (s[*i + *j] && s[*i + *j] != c)
    {
        if (s[*i + *j] == '\"' || s[*i + *j] == '\'')
        {

            if (s[*i + *j] == '\"') {
                (*j)++;
                while (s[*i + *j] && s[*i + *j] != '\"')
                    (*j)++;
            }
            if (s[*i + *j] == '\'') {
                (*j)++;
                while (s[*i + *j] && s[*i + *j] != '\'')
                    (*j)++;
            }
        }
        else
            (*j)++;
    }
}

// case to handle
// echo yolol="echo $PWD"
//

static int	ft_split_write(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i])
		{
			ft_split_write_extend(&i, &j, s, c);
			if (j > 0)
			{
				dest[word] = (char *)malloc(sizeof(char) * (j + 1));
				if (!dest[word])
					return (dest[word] = NULL, ft_split_free(dest), 1);
				ft_split_write_word(dest[word], s, i, j);
				word++;
			}
			i += j;
		}
	}
	dest[word] = NULL;
	return (0);
}

char	**split_element(char *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!dest)
		return (free(s), NULL);
	if (ft_split_write(dest, s, c))
        return (free(s), NULL);
    free(s);
	return (dest);
}
