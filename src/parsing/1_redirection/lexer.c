/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:51:50 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:47:39 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char **add_line(char **in, char *to_add)
{
    char **dup;
    int lines;
    int i;

    lines = nbr_of_line(in);
    dup = (char **)malloc(sizeof(char *) * (lines + 2));
    if (!dup)
        return (free_env(in), NULL);
    i = 0;
    while (in[i])
    {
        dup[i] = ft_strdup(in[i]);
        if (!dup[i])
            return (dup[i] = NULL, free_env(dup), free_env(in), NULL);
        i++;
    }
    if (to_add)
    {
        dup[i] = ft_strdup(to_add);
        if (!dup[i])
            return (dup[i] = NULL, free_env(dup), free_env(in), NULL);
        i++;
    }
    dup[i] = NULL;
    free_env(in);
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
    redir = (char **) malloc(sizeof (char *));
    if (!redir)
        return (NULL);
    *redir = NULL;
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

bool check_redir(char *in)
{
    int i = 0;
    while(in[i])
    {
        if (in[i] == '<' || in[i] == '>')
            return (true);
        i++;
    }
    return (false);
}

char **redir_special(char *in)
{
    int end = 0;
    int len = ft_strlen(in);
    char **res = (char **)malloc(sizeof(char *) * 3);

    if (!res)
        return (NULL);
    while (in[end] && in[end] != '<' && in[end] != '>')
        end++;
    res[0] = (char *)malloc(sizeof(char) * (end + 1));
    if (!res[0])
        return (free_env(res), NULL);
    ft_strlcpy(res[0], in, end + 1);
    res[1] = (char *)malloc(sizeof(char) * (len - end + 1));
    if (!res[1])
        return (free_env(res), NULL);
    ft_strlcpy(res[1], in + end, len - end + 1);
    res[2] = NULL;
    return (res);
}


char	**relexer(char **in)
{
	char	**res;
	char	**line;
    char    **special;
	int		i;
	int		k;

	i = 0;
    res = (char **) malloc(sizeof(char *));
    if (!res)
        return (free_env(in), NULL);
    *res = NULL;
	while (in[i])
	{
		k = 0;
		if (in[i][0] == '<' || in[i][0] == '>')
		{
			line = get_redir(in[i]);
            if (!line)
                return (free_env(in), NULL);
			while (line[k])
			{
				res = add_line(res, line[k]);
                if (!res)
                    return (free_env(in), NULL);
				k++;
			}
            free_env(line);
		}
		else
        {
            if (check_redir(in[i]))
            {
                line = redir_special(in[i]);
                res = add_line(res, line[0]);
                if (!res)
                    return (free_env(in), NULL);
                special = get_redir(line[1]);
                while (special[k])
                {
                    res = add_line(res, special[k]);
                    if (!res)
                        return (free_env(in), NULL);
                    k++;
			    }
                free_env(line);
                free_env(special);
            }
            else
                res = add_line(res, in[i]);
        }
		i++;
	}
    free_env(in);
	return (res);
}
