/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:02:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/06 23:02:54 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	in_quote(int status, char type)
{
	if (type == '\"' && status == 0)
		return (1);
	else if (type == '\'' && status == 0)
		return (-1);
	else if ((type == '\"' && status == 1) || (type == '\'' && status == -1))
		return (0);
	return (status);
}

char	**remove_quote(char **arg)
{
	int		i;
	int		j;
	char	**res;
	int		status;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (nbr_of_line(arg) + 1));
	if (!res)
		return (free_env(arg), NULL);
	while (arg[i])
	{
		j = 0;
		status = 0;
		res[i] = ft_strdup("");
		if (!res[i])
			return (free_env(res), free_env(arg), NULL);
		while (arg[i][j])
		{
			if ((arg[i][j] == '\'' || arg[i][j] == '\"') && status == 0)
			{
				status = in_quote(status, arg[i][j]);
				j++;
			}
			else if ((arg[i][j] == '\'' && status == -1) || (arg[i][j] == '\"'
					&& status == 1))
			{
				status = in_quote(status, arg[i][j]);
				j++;
			}
			else
			{
				res[i] = add_char(res[i], arg[i][j]);
				if (!res[i])
					return (free_env(res), free_env(arg), NULL);
				j++;
			}
		}
		i++;
	}
	res[i] = NULL;
	free_env(arg);
	return (res);
}
