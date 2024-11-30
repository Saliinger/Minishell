/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:47:15 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/30 16:13:55 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*expanded(t_minishell *minishell, char *var, int type)
{
	char	*res;
	int		len;
	int		line;

	len = ft_strlen(var);
	line = get_env_var(minishell, var, len - type);
	if (line == -1)
		return (NULL);
	res = ft_strdup(minishell->env[line] + len + 1 - type);
	return (res);
}

char	**expand_in(char **arg, t_minishell *minishell)
{
	int		i;
	char	**new_arg;

	new_arg = (char **)malloc(sizeof(char *) * (nbr_of_line(arg) + 1));
	if (!new_arg)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == '$')
			new_arg[i] = expanded(minishell, arg[i] + 1, 0);
        else if (arg[i][0] == '\"' && arg[i][1] == '$')
            new_arg[i] = expanded(minishell, arg[i] + 2, 1);
		else
			new_arg[i] = ft_strdup(arg[i]);
		i++;
	}
	new_arg[i] = NULL;
	free_env(arg);
	return (new_arg);
}
