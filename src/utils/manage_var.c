/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:59:26 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/07 10:41:54 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**remove_env(char **env, int to_delete)
{
	char	**res;
	int		len;
	int		i;
	int		j;

    if (to_delete < 0)
        return (env);
    i = 0;
	j = 0;
	len = nbr_of_line(env);
	res = (char **)malloc(sizeof(char *) * len + 1);
	if (!res)
		return (ft_free_tab(env), NULL);
	while (env[j])
	{
		if (j == to_delete)
			j++;
		else
		{
			res[i] = ft_strdup(env[j]);
			i++;
			j++;
		}
	}
	res[i] = NULL;
	ft_free_tab(env);
	return (res);
}

//char	**add_env(char **env, char *to_add)
//{
//	char	**res;
//	int		len;
//	int		i;
//
//    if (!to_add)
//        return (env);
//    i = 0;
//	len = nbr_of_line(env);
//	res = (char **)malloc(sizeof(char *) * len + 2);
//	if (!res)
//		return (NULL);
//	while (env[i])
//	{
//		res[i] = ft_strdup(env[i]);
//		i++;
//	}
//    res[i] = ft_strdup(to_add);
//	res[i + 1] = NULL;
//	ft_free_tab(env);
//	return (res);
//}

int	create_var(t_minishell *minishell, char *var)
{
	minishell->env = add_line(minishell->env, var);
	if (!minishell->env)
		return (1);
	return (0);
}

int	delete_var(t_minishell *minishell, int line)
{
	minishell->env = remove_env(minishell->env, line);
	if (!minishell->env)
		return (1);
	return (0);
}
