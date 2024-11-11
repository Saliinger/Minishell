/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:37:23 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 11:46:50 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_home(t_minishell *minishell)
{
	int		home_line;
	char	*home;
	char	*temp;
	int		i;

	home_line = get_env_var(minishell, "HOME", 4);
	if (home_line < 0)
		return (NULL);
	temp = ft_strdup(minishell->env[home_line]);
	i = 0;
	while (temp[i] && temp[i] != '=')
		i++;
	if (temp[i] == '=')
		i++;
	home = ft_strdup(temp + i);
	free(temp);
	return (home);
}
