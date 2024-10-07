/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:23:53 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/08 01:25:30 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdio.h>

bool	checker_command(char *in, char *command)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (in[i])
	{
		if (in[i] != command[j])
			break ;
		i++;
		j++;
	}
	if (i == ft_strlen(command))
		return (true);
	else
		return (false);
}

int	nbr_of_line(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**get_env(char **env)
{
	int		i;
	char	**res;
	int		nbr_lines;

	i = 0;
	nbr_lines = nbr_of_line(env);
	if (!env)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (nbr_lines + 1));
	if (!res)
		return (NULL);
	while (i < nbr_lines)
	{
		res[i] = ft_strdup(env[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_print(char **s, int i)
{
	if (!s)
	{
		printf("Error: NULL pointer passed to ft_print.\n");
		return ;
	}
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}

void	ft_print_redir(t_redir *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("node %d: %s\n", i, list->redir);
		i++;
		list = list->next;
	}
}
