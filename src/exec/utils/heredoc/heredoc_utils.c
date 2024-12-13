/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:51:05 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:52:43 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

/**
 * brief : returns the expanded value (after the =), or NULL if var not found.
 * 
 */
char	*get_env_value(char **env, const char *var)
{
	size_t	len;
	int		i;

	len = strlen(var);
	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (strdup(&env[i][len + 1]));
		i++;
	}
	return (strdup(""));
}

char	*append_to_result(char *result, const char *start, size_t len)
{
	char	*tmp;
	char	*new_result;

	tmp = ft_substr(start, 0, len);
	new_result = ft_strjoin_frees1(result, tmp);
	free(tmp);
	return (new_result);
}

/**
 * brief : finds the next '$' in line and returns the len until '$'
 * 
 */
size_t	find_next_dollar(const char *line, size_t start)
{
	size_t	len;

	len = 0;
	while (line[start + len] && line[start + len] != '$')
		len++;
	return (len);
}
