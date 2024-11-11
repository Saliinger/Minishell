/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:37:06 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 16:36:15 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*path_constructor(t_minishell *minishell, char *in)
{
	char	*res[PATH_MAX];
	char	*current_path;
	int		i;
	char	*res;
	char	**in_cut;

	in_cut = ft_split(in, '/');
	if (in_cut[0] == '~')
	{
		current_path = get_home(minishell);
		i = 1;
	}
	else
	{
		current_path = get_current_path(minishell);
		i = 0;
	}
	while (in[i])
	{
		
		i++;
	}
	free(current_path);
	return (res);
}
