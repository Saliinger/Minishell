/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_minishell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:33:54 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/10 01:43:32 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

/**
 * brief : frees the n elements of the tab
 * 
 */
void	free_tab_elems(char **tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(tab[i]);
	}
}

/**
 * brief : frees the elements of the NULL terminated 2D char tab, then frees the tab;
 * 
 */
void	free_nullterm_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	tab = NULL;
	free(tab);
}

/**
 * brief : frees the elements of the node
 * 
 */
static void	free_mini_elems(t_minishell *m)
{
	free_nullterm_tab(m->env);
	free_nullterm_tab(m->hidden_env);
	free_nullterm_tab(m->paths);
	free_tab_elems(m->builtins_paths, NB_BUILTINS);
	free(m->pwd);
	free(m->old_pwd);
}

/**
 * brief : frees the elements of the t_minishell then frees the t_minishell;
 *
 */
void	free_t_minishell(t_minishell *m)
{
	free_mini_elems(m);
	m = NULL;
	free(m);
}
