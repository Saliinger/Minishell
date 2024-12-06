/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:04:25 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/06 23:04:26 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*add_char(char *s, char c)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (free(s), NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	free(s);
	return (res);
}
