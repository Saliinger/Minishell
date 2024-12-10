/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_minishell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:33:54 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/01 19:21:11 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"


/**
 * brief : frees the elements of the NULL terminated 2D char tab, then frees the tab, and sets it's address to NULL;
 * 
 */
void	ft_free_nullterm_tab(char ***ptab)
{
	char **tab;
	int	i;

	if (!ptab || !*ptab)
		return ;
	tab = *ptab;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	*ptab = NULL;
}

/**
 * brief : frees the elements of the node
 * 
 */
//static void	free_mini_elems(t_minishell *m)
//{
////	ft_free_nullterm_tab(&m->env);
////	ft_free_nullterm_tab(&m->hidden_env);
////	ft_close_saved_std_fds(m->std_fds);
////	//ft_free_nullterm_tab(&m->hidden_path); // am I even needed ?
////	//ft_free_nullterm_tab(&m->paths);
////	ft_free((void **) &m->pwd);
////	ft_free((void **) &m->old_pwd);
////	//ft_free_nullterm_tab(&m->hd);
//
//}

/**
 * in : ms is &m, where m is a t_minishell *m
 * brief : frees the elements of the t_minishell then frees the t_minishell;
 * sets the m to NULL
 * 
 */
void	free_t_minishell(t_minishell **ms)
{
	t_minishell *m;

	if (!ms || !*ms)
		return ;
	m = *ms;
//	free_mini_elems(m);
//	free (m);
//	*ms = NULL;
    free_minishell(m);
}
