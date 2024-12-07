/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:13:49 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:46:59 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include <time.h>

static bool	is_redirection(char *arg)
{
	return (!ft_strncmp(arg, "<", 1) || !ft_strncmp(arg, ">", 1)
		|| !ft_strncmp(arg, "<<", 2) || !ft_strncmp(arg, ">>", 2));
}

static int	count_line(char **arg)
{
	int	i;
	int	nbr_line;

	nbr_line = 0;
	i = 0;
	while (arg[i])
	{
		if (!is_redirection(arg[i]) && (i == 0 || !is_redirection(arg[i - 1])))
			nbr_line++;
		i++;
	}
	return (nbr_line);
}

char	**clean_arg(char **arg)
{
	char	**res;
	int		i;
	int		j;
	int		nbr_line;

	i = 0;
	j = 0;
	nbr_line = count_line(arg);
	res = (char **)malloc(sizeof(char *) * (nbr_line + 1));
	if (!res)
		return (NULL);
	while (j < nbr_line)
	{
		while (is_redirection(arg[i]))
			i++;
		while (i > 0 && is_redirection(arg[i - 1]))
			i++;
		res[j] = ft_strdup(arg[i]);
		j++;
		i++;
	}
	res[j] = NULL;
	return (res);
}
