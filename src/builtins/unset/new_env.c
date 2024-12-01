/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:50:55 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:51:37 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	count_line(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**new_env(t_minishell *minishell, int *to_remove, int nbr_of_line)
{
	int		i;
	int		g;
	int		to_remove_idx;
	char	**new_env;
	int		env_size;

	env_size = count_line(minishell->env);
	new_env = (char **)malloc(sizeof(char *) * (env_size - nbr_of_line + 1));
	if (!new_env)
		return (free_env(minishell->env), NULL);
	i = 0;
	g = 0;
	to_remove_idx = 0;
	while (minishell->env[i])
	{
		if (to_remove_idx < nbr_of_line && i == to_remove[to_remove_idx])
			to_remove_idx++;
		else
		{
			new_env[g] = ft_strdup(minishell->env[i]);
			g++;
		}
		i++;
	}
	new_env[g] = NULL;
	free_env(minishell->env);
	return (new_env);
}
