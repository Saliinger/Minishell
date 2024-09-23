/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:35:20 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/23 00:06:14 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/**
 * in : e is &end, where env is a char **env
 * brief : frees char * in env, then env,
 * then sets env to NULL
 * 
 */
void	free_env(char ***e)
{
	char **env;
	int	i;

	env = *e;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	*e = NULL;
}
