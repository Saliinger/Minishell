/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:35:20 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 17:25:05 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
    free(env);
    env = NULL;
}

void free_export_list(t_export_list **list)
{
    t_export_list *temp;

    while(*list)
    {
        temp = (*list)->next;
        free((*list)->name);
        free((*list)->value);
        free((*list));
        *list = temp;
    }
    free(list);
}

void	free_minishell(t_minishell *minishell)
{
     if (minishell->pwd) {
         printf("pwd: %s\n", minishell->pwd);
         free(minishell->pwd);
     }
    if (minishell->old_pwd)
		free(minishell->old_pwd);
	if (minishell->env)
		free_env(minishell->env);
	if (minishell->paths)
		free_env(minishell->paths);
	if (minishell->hidden_env)
		free_env(minishell->hidden_env);
	if (minishell->hidden_env)
		free_env(minishell->hidden_env);
	if (minishell->hd)
		free_env(minishell->hd);
    if (minishell->exportList)
        free_export_list(minishell->exportList);
    minishell = NULL;
}


