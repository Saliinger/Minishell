/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:35:20 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/09 15:55:41 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_env(char **env)
{
	int			i;
	static int	o = 0;

	o++;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	if (env)
		free(env);
	env = NULL;
}

void	free_minishell(t_minishell *minishell)
{
	if (!minishell)
	{
		minishell = NULL;
		return ;
	}
	if (minishell->env)
		free_env(minishell->env);
	if (minishell->paths)
		free_env(minishell->paths);
	if (minishell->hidden_env)
		free_env(minishell->hidden_env);
	if (minishell->hidden_path)
		free_env(minishell->hidden_path);
	if (minishell->hd)
		free_env(minishell->hd);
	minishell = NULL;
}

// if (minishell->pwd)
//	printf("pwd: %s\n", minishell->pwd);
// free(minishell->pwd);
// if (minishell->old_pwd)
//		free(minishell->old_pwd);