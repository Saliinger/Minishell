/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:37:06 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:50:02 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	remove_path(char *dest)
{
	int	len;

	len = ft_strlen(dest);
	while (dest[len] != '/')
	{
		dest[len] = '\0';
		len--;
	}
}

static void	add_path(char *dest, char *to_add)
{
	int	j;
	int	i;
	int	len;

	len = ft_strlen(dest);
	dest[len] = '/';
	j = len + 1;
	i = 0;
	while (to_add[i])
	{
		dest[j] = to_add[i];
		j++;
		i++;
	}
	dest[j] = '\0';
}

static int	init_path(char *current_path, char **in_cut, t_minishell *minishell)
{
	size_t	temp_size;
	char	*temp;

	if (*in_cut[0] == '~')
	{
		temp = get_home(minishell);
		temp_size = ft_strlen(temp);
		ft_strlcpy(current_path, temp, temp_size);
		free(temp);
		return (1);
	}
	else
	{
		temp = get_current_path(minishell);
		temp_size = ft_strlen(temp);
		ft_strlcpy(current_path, temp, temp_size + 1);
		fprintf(stderr, "%s\n", current_path);
		free(temp);
		return (0);
	}
}

char	*path_constructor(t_minishell *minishell, char *in)
{
	char	*res;
	char	current_path[PATH_MAX];
	int		i;
	int		j;
	char	**in_cut;

	in_cut = ft_split(in, '/');
	i = init_path(current_path, in_cut, minishell);
	while (in_cut[i])
	{
		j = 0;
		if (ft_strlen(in_cut[i]) <= 3)
		{
			while (in_cut[i][j] && in_cut[i][j] == '.')
				j++;
			if (j == 2)
				remove_path(current_path);
			else if (j > 2)
				add_path(current_path, in_cut[i]);
		}
		else
			add_path(current_path, in_cut[i]);
		i++;
	}
	res = ft_strdup(current_path);
	return (res);
}

// ../
// ./
//
// all the function need to write in the dest