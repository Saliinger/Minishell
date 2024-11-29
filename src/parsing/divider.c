/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divider.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:21:21 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:47:07 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_pipe(char *in)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (in[i])
	{
		if (flag == 0 && in[i] == '|')
			return (i);
		if (in[i] == '"')
		{
			while (in[i] != '"')
				i++;
		}
		if (in[i] == '\'')
		{
			while (in[i] != '\'')
				i++;
		}
		i++;
	}
	return (0);
}
