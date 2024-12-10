/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:13 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/10 12:51:27 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_path(char *in, t_minishell *minishell)
{
	char	*res;

	if (!in || (ft_strlen(in) == 1 && *in == '~') || (ft_strlen(in) == 1
			&& *in == '/'))
	{
		res = get_home(minishell);
		if (!res)
			perror("Error: Home is not set\n");
	}
	else
		res = path_constructor(minishell, in);
	return (res);
}
