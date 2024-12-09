/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divider.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:21:21 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/09 18:34:31 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_pipe(char *in)
{
	int	i;
	int	flag;
	int	str_len;

	i = 0;
	flag = 0;
	str_len = ft_strlen(in);
	while (i < str_len && in[i])
	{
		if (in[i] == '|')
			return (i);
		if (in[i] == '\'' || in[i] == '\"')
		{
			flag = in_quote(flag, in[i]);
			if (in[i] == '\'' || in[i] == '\"')
				i++;
			while (in[i] && flag != 0)
			{
				flag = in_quote(flag, in[i]);
				i++;
			}
			i++;
		}
		else
			i++;
	}
	return (0);
}
