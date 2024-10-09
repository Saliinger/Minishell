/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:13:49 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/09 15:28:56 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_redirection(char *arg)
{
	return (!ft_strncmp(arg, "<", 1) || !ft_strncmp(arg, ">", 1)
		|| !ft_strncmp(arg, "<<", 2) || !ft_strncmp(arg, ">>", 2));
}

char	**clean_arg(char **arg)
{
	char	**res;
	int		i;
	int		j;
	int		nbr_line;

	i = 0;
	j = 0;
	nbr_line = 0;
	while (arg[i])
	{
		if (!is_redirection(arg[i]) && (i == 0 || !is_redirection(arg[i - 1])))
			nbr_line++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (nbr_line + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		if (!is_redirection(arg[i]) && (i == 0 || !is_redirection(arg[i - 1])))
		{
			res[j] = ft_strdup(arg[i]);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
