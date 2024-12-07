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
        }
        if (in[i] == '|')
			return (i);
		i++;
	}
	return (0);
}
