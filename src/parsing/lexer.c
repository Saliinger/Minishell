/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:51:50 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/27 14:26:45 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**add_line(char **in, char *to_add)
{
	char	**dup;
	int		lines;
	int		i;

	if (in)
		lines = nbr_of_line(in);
	else
		lines = 0;
	dup = (char **)malloc(sizeof(char *) * (lines + 2));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		dup[i] = ft_strdup(in[i]);
		i++;
	}
	if (to_add)
	{
		dup[i] = ft_strdup(to_add);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static char	*get_part(char *in, int start, int len)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && in[start + i])
	{
		res[i] = in[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**get_redir(char *in)
{
	int		k;
	int		car;
	char	*line;
	char	**redir;

	k = 0;
	redir = NULL;
	while (in[k])
	{
		car = 0;
		while (in[k + car] && (in[k + car] == '<' || in[k + car] == '>'))
			car++;
		if (car > 0)
		{
			line = get_part(in, k, car);
			redir = add_line(redir, line);
			free(line);
			k += car;
		}
		car = 0;
		while (in[k + car] && (in[k + car] != '<' && in[k + car] != '>'))
			car++;
		if (car > 0)
		{
			line = get_part(in, k, car);
			redir = add_line(redir, line);
			free(line);
			k += car;
		}
	}
	return (redir);
}

char	**relexer(char **in)
{
	char	**res;
	char	**line;
	int		i;
	int		k;

	res = NULL;
	i = 0;
	while (in[i])
	{
		k = 0;
		if (in[i][0] == '<' || in[i][0] == '>')
		{
			line = get_redir(in[i]);
			while (line[k])
			{
				res = add_line(res, line[k]);
				k++;
			}
		}
		else
			res = add_line(res, in[i]);
		i++;
	}
	return (res);
}
