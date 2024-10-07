/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:36:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/07 22:40:23 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_redir(char *in)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (in[i])
	{
		if (in[i] == '<' || in[i] == '>')
		{
		}
	}
	return (res);
}

char	**set_redir(char *in)
{
	char	**res;
}
