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
	if (len == 0)
		return; // Nothing to remove

	// Move backward until finding a '/' or reaching the beginning
	while (len > 0 && dest[len - 1] != '/')
		len--;

	// If `len` is 0, it means we are at the root `/`
	if (len == 0)
		dest[0] = '\0'; // Reset dest to an empty string
	else
		dest[len - 1] = '\0'; // Remove the last segment
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


// init path handle the start of the path that we wan't to go to ~ / or nothing
static int	init_path(char *in, t_minishell *minishell, char **new_in)
{
	char	*temp;

    if (!in)
        return (0);
    if (*in == '~' || *in == '/')
	{
		temp = get_home(minishell);
        if (*in != '~' && ft_strncmp(temp, in, ft_strlen(temp)) != 0)
            *new_in = ft_strjoin(temp, in);
        else if (ft_strncmp(temp, in, ft_strlen(temp)) != 0)
            *new_in = ft_strjoin(temp, in + 1);
        else
            *new_in = ft_strdup(in);
		free(temp);
	}
    else
	{
		temp = get_current_path(minishell);
        if (ft_strncmp(temp, in, ft_strlen(temp)) != 0)
        {
            if (*in != '/')
                temp = ft_strjoin_frees1(temp, "/");
            *new_in = ft_strjoin(temp, in);
        }
        else
            *new_in = ft_strdup(in);
		free(temp);
	}
    return (0);
}

bool check_dot(char *in)
{
    int i = 0;
    int nbr = 0;

    if (!in)
        return (0);
    while (in[i])
    {
        if (in[i] == '.')
            nbr++;
        while (in[i] == '.')
            i++;
        i++;
    }
    return (nbr);
}

char	*path_constructor(t_minishell *minishell, char *in)
{
	char	*res;
    char    *new_in;
	char	current_path[PATH_MAX];
	int		i;
	int		j;
	char	**in_cut;

    new_in = NULL;
    i = init_path(in, minishell, &new_in);
    if (!check_dot(new_in))
        return (new_in);
    in_cut = ft_split(new_in, '/');
	while (in_cut[i])
	{
		j = 0;
		if (ft_strlen(in_cut[i]) <= 3 && in_cut[i][j] == '.')
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
    ft_free_tab(in_cut);
    free(new_in);
	return (res);
}

// ../
// ./
//
// all the function need to write in the dest