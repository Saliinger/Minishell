/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:37:06 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/12 16:01:02 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void remove_path(char *dest ,char *path)
{
	int		len;

	len = ft_strlen(path);
	while (path[len] != '/')
		len--;
	ft_strlcpy(dest, path, len);
}

static void	add_path(char *dest, char *path, char *to_add, int *i)
{
	int		j;
	int		len;

	j = *i;
	while (to_add[j] && to_add[j] != '/')
		j++;
	len = ft_strlen(path);
}

char	*path_constructor(t_minishell *minishell, char *in)
{
	char	*res;
	char	current_path[PATH_MAX];
	int		i;
	char	**in_cut;
	char	*temp;

	in_cut = ft_split(in, '/');
	if (*in_cut[0] == '~')
	{
		temp = get_home(minishell);
		i = 1;
	}
	else
	{
		temp = get_current_path(minishell);
		i = 0;
	}
	while (in[i])
	{
		if (in[i] == '.' && in[i + 1] == '.' && in[i + 2] == '/')
		{
			current_path = remove_path(current_path);
			i += 3;
		}
		else if (in[i] == '.' && in[i + 1] == '/')
			i += 2;
		
		i++;
	}
	return (res);
}

// ../
// ./
//
// all the function need to write in the dest 
