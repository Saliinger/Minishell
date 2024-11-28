/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:46:44 by mlapique          #+#    #+#             */
/*   Updated: 2024/11/28 05:23:33 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

char	*word_after_expand(char *word, int *error, char *exp)
{
	int		i;
	int		j;
	char	*result;

	if (*error != 0)
		return (NULL);
	result = ft_calloc(1, ft_strlen(word) + 1);
	if (!result)
		return (*error = -10, NULL);
	i = 0;
	j = 0;
	while (word && word[i] && &word[i] <= exp)
		i++;
	while (word && word[i] && (ft_isalnum(word[i]) || word[i] == '_'))
		i++;
	if (word[i] == '?')
		i++;
	while (word && word[i])
	{
		result[j] = word[i];
		i++;
		j++;
	}
	return (result);
}

char	*word_before_expand(char *word, int *error, char *exp)
{
	int		i;
	char	*result;

	if (*error != 0)
		return (NULL);
	result = ft_calloc(1, ft_strlen(word) + 1);
	if (!result)
		return (*error = -10, NULL);
	i = 0;
	while (word && word[i] && &word[i] < exp)
	{
		result[i] = word[i];
		i++;
	}
	return (result);
}

char	*just_what_to_expand(char *dollar, int *error)
{
	int		i;
	char	*new;

	if (*error != 0)
		return (NULL);
	i = 1;
	new = ft_calloc(ft_strlen(dollar) + 1, 1);
	if (!new)
		return (*error = -10, NULL);
	if (dollar[0] && dollar[1])
	{
		while (ft_isalnum(dollar[i]) || dollar[i] == '_')
		{
			new[i - 1] = dollar[i];
			i++;
		}
		if (dollar[1] == '?')
			new[i - 1] = '?';
	}
	return (new);
}

char	*its_looping_time(char **word, t_minishell *m, int *error, bool heredoc)
{
	char	*before;
	char	*after;
	char	*exp;
	int		i;

	i = 0;
	while (word && *word && ft_strchr(&(*word)[i], '$'))
	{
		exp = get_next_expandable(word, heredoc);
		if (!exp)
			return (*word);
		before = word_before_expand(*word, error, exp);
		after = word_after_expand(*word, error, exp);
		exp = just_what_to_expand(exp, error);
		exp = expand(m, exp, error);
		free(*word);
		if (*error != 0)
			return (NULL);
		*word = result_new_word(&before, &exp, &after, error);
		if (*error != 0)
			return (NULL);
	}
	return (*word);
}
