/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:37:06 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 14:36:01 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	remove_path(char *dest, char *path)
{
	int	len;

	len = ft_strlen(path);
	while (path[len] != '/')
		len--;
	ft_strlcpy(dest, path, len);
}

static void	add_path(char *dest, char *path, char *to_add, int *i)
{
	int	j;
	int	len;

	j = *i;
	while (to_add[j] && to_add[j] != '/')
		j++;
	len = ft_strlen(path);
}

static void	init_path(char *current_path, char **in_cut, t_minishell *minishell,
		int *i)
{
	char	*temp;

	if (*in_cut[0] == '~')
	{
		temp = get_home(minishell);
		ft_strlcpy(current_path, temp, ft_strlen(temp));
		free(temp);
		*i = 1;
	}
	else
	{
		temp = get_current_path(minishell);
		ft_strlcpy(current_path, temp, ft_strlen(temp));
		free(temp);
		*i = 0;
	}
}

char	*path_constructor(t_minishell *minishell, char *in)
{
	char	*res;
	char	current_path[PATH_MAX];
	int		i;
	char	**in_cut;

	in_cut = ft_split(in, '/');
	init_path(current_path, in_cut, minishell, &i);
	while (in_cut[i])
	{
		if (ft_strlen(in_cut[i]) <= 3)
		{
		}
		else
		{
			ft_strjoin(current_path, "/");
			ft_strjoin(current_path, in[i]);
			ft_strjoin(current_path, "/");
		}
		i++;
	}
	return (res);
}

// ../
// ./
//
// all the function need to write in the dest
