/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:32:48 by mlapique          #+#    #+#             */
/*   Updated: 2024/11/28 05:23:42 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2024/11/25 11:24:51 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

static	char	*join_free_null_protected(char *first, \
char *second, int *error, int hard)
{
	char	*result;

	result = join_with_null_protection(first, second, error);
	if (!result)
		return (free(first), free(second), NULL);
	if (*error != 0)
	{
		if (hard == 0)
			return (free(first), free(second), NULL);
		if (hard == 1)
			return (free(first), NULL);
		if (hard == 2)
			return (NULL);
	}
	if (hard == 0)
		return (free(first), free(second), result);
	if (hard == 1)
		return (free(first), result);
	if (hard == 2)
		return (result);
	return (result);
}

char	*heredoc(char *key, t_minishell *m, bool expand, int *error)
{
	char	*tmp;
	char	*result;

	result = NULL;
	while (1)
	{
		tmp = readline(">");
		if (g_sig == SIGINT)
		{
			g_sig = NO_SIG;
			if (restore_std_fds(m->std_fds) == -1)
				*error = ERR;
			return (free(tmp), free(result), NULL);
		}
		if (!tmp)
			return (ft_print_err("minishell: warning: %s (wanted `%s')", \
				"here-document delimited by end-of-file", key), result);
		if (ft_strcmp(tmp, key) == 0)
			return (free(tmp), result);
		if (expand == true && ft_strchr(tmp, '$'))
			tmp = its_looping_time(&tmp, m, error, true);
		tmp = join_free_null_protected(tmp, "\n", error, 1);
		if (!tmp)
			return (NULL);
		result = join_free_null_protected(result, tmp, error, 0);
		if (!result)
			return (free(tmp), NULL);
	}
	return (result);
}
