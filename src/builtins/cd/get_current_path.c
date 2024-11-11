/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:39:03 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 11:46:15 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_current_path(t_minishell *minishell)
{
	char	*current_path;
	char	*temp;
	char	*res;
	int		line;

	line = get_env_var(minishell, "PWD", 3);
	if (line < 0)
		return (NULL);
	current_path = ft_strdup(minishell->env[line]);
	if (!current_path)
		return (NULL);
	temp = current_path;
	while (*temp && *temp != '=')
		temp++;
	if (*temp == '=')
		temp++;
	res = ft_strdup(temp);
	free(current_path);
	return (res);
}
