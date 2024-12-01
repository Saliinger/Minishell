/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:00:29 by mlapique          #+#    #+#             */
/*   Updated: 2024/11/28 23:36:14 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

// int	put_in_tab(char **result, int which_quotes, char *word)
// {
// 	char	**tmp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = i;
// 	while (result && result[i])
// 		i++;
// 	i--;
// 	if (which_quotes == 0)
// 	{
// 		tmp = ft_split(word, ' ');
// 		if (!tmp)
// 			return (-10);
// 		while (tmp && tmp[j] && result && result[i])
// 		{
// 			result[i] = tmp[j];
// 			i++;
// 			j++;
// 		}
// 	}
// 	else
// 		result[i] = word;
// 	return (i);
// }

// char	*join_with_null_protection(char *first, char *second, int *error)
// {
// 	char	*tmp;

// 	tmp = NULL;
// 	if (!first && !second)
// 		return (NULL);
// 	if (!first)
// 		tmp = ft_strdup(second);
// 	else if (!second)
// 		tmp = ft_strdup(first);
// 	else
// 		tmp = ft_strjoin(first, second);
// 	if (!tmp)
// 		*error = -10;
// 	return (tmp);
// }

// bool	verif_redir(char *word, int *error)
// {
// 	int		i;
// 	char	*test;
// 	int		nb_word;

// 	i = 0;
// 	nb_word = 0;
// 	if (word == NULL)
// 		return (true);
// 	while (word && word[i])
// 	{
// 		i += ignore_whitespace(&word[i]);
// 		test = getword(&word[i], &i);
// 		if (!test)
// 			return (*error = -1, false);
// 		free(test);
// 		nb_word++;
// 		if (nb_word > 1)
// 			return (true);
// 	}
// 	return (false);
// }

// bool	expandable_rules(char *exp, bool heredoc, int in_quotes)
// {
// 	bool	white_space;
// 	bool	ignorable_quotes;

// 	ignorable_quotes = false;
// 	white_space = false;
// 	if (heredoc == false)
// 	{
// 		if (exp[1] == ' ' || (exp[1] > 8 && exp[1] < 13) || exp[1] == '\0')
// 			white_space = true;
// 		else if (exp[1] == in_quotes)
// 			ignorable_quotes = true;
// 		if (white_space == true || ignorable_quotes == true)
// 			return (false);
// 		return (true);
// 	}
// 	if (exp[1] == ' ' || (exp[1] > 8 && exp[1] < 13) || exp[1] == '\0')
// 		white_space = true;
// 	if (exp[1] == '\'' || exp[1] == '"')
// 		ignorable_quotes = true;
// 	if (white_space == true || ignorable_quotes == true)
// 		return (false);
// 	return (true);
// }

// char	*get_next_expandable(char **word, bool heredoc)
// {
// 	char	*exp;
// 	int		i;
// 	int		in_quotes;

// 	i = 0;
// 	in_quotes = 0;
// 	// if (heredoc == true)
// 	// 	return (ft_strchr(*word, '$'));
// 	exp = ft_strchr(*word, '$');
// 	while (exp)
// 	{
// 		in_quotes = between_single_quotes(*word, exp);
// 		if (expandable_rules(exp, heredoc, in_quotes) == true)
// 			return (exp);
// 		// if (between_single_quotes(*word, exp) != SINGLE_QUOTES && exp[1] != '\0' && (exp[1] < 8 || exp[1] > 13) && heredoc == false && exp[1] != ' ' && exp[1] != '\'')
// 		// 	return (exp);
// 		// else if (exp[1] != '\0' && (exp[1] < 8 || exp[1] > 13) && heredoc == true && exp[1] != ' ')
// 		// 	return (exp);
// 		i++;
// 		exp = ft_strchr(&(word[0][i]), '$');
// 	}
// 	return (exp);
// }
