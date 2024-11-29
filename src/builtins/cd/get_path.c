/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:13 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:49:56 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_path(char *in, t_minishell *minishell)
{
	char	*res;

	if (!in)
	{
		res = get_home(minishell);
		if (!res)
			perror("Error: Home is not set\n");
		return (res);
	}
	if (is_symlink(in))
		res = path_constructor(minishell, in);
	else
		res = ft_strdup(in);
	return (res);
}

// if !path || ~ => go to home
// else use comand->arg[1] + check if symlink
