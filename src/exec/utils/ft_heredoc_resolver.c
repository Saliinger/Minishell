/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_resolver.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 06:28:29 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 17:30:20 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

char *expand_str(char *str, t_minishell *m)
{
	(void) str;
	(void) m;
	//look for magic $
		//skip the ' ' parts
	//resolve the " " & ' ' ?
	//get expand_key after the $ 
	//expand the expand_key 
	return (NULL);
}


/**
 * 
 * brief : gets the expansion mode from the given key symbols, also changes the key to the actual key we'll be looking for with check_key(str, key).
 * 
 */
bool	get_expansion_mode(char **key)
{
	int len;

	len = ft_strlen(*key);
	if ((*key[0] == '\'' && *key[len] == '\'') || (*key[0] == '\"' && *key[len] == '\"'))
	{
		//get them off modif key to the actual key
		return(true);
	}
	return (false);
}

/**
 * brief: checks if str_to_check is the key
 * 
 */
int check_key(char *str_to_check, char *key)
{
	size_t i;

	if (!str_to_check || !key || !str_to_check[0] || !key[0])
		return (printf("\n %s, %s:%d heredoc failed\n", __FILE__, __FUNCTION__, __LINE__), ERR);
	if (ft_strlen(str_to_check) != ft_strlen(key))
		return (false);
	i = 0;
	while (str_to_check[i] && key[i])
	{
		if (str_to_check[i] != key[i])
			return (false);
		i++;
	}
	return (true);
}

/**
 * brief: executes the heredoc, returns the heredoc'ed txt
 * 
 */
char *ft_resolve_heredoc(char *key, t_minishell *m)
{
	char	*heredoc_str;
	char	*new_line;
	bool	expansion;
	int		done;

	expansion = get_expansion_mode(&key);
	heredoc_str = malloc(sizeof(char));
	heredoc_str[0] = '\0';
	done = false;
	while (!done)
	{
		new_line = readline("> ");
		done = check_key(new_line, key);
		if (!new_line || done == ERR || !heredoc_str)
			return (printf("\n %s, %s:%d heredoc failed\n", __FILE__, __FUNCTION__, __LINE__), free(heredoc_str), NULL);
		if (done)
			break;
		heredoc_str = ft_strjoin_frees1(heredoc_str, "\n");
		if (!heredoc_str || !new_line)
			return (free(new_line), NULL);
		heredoc_str = ft_strjoin_frees1(heredoc_str, new_line);
		if (!heredoc_str || !new_line)
			return (free(new_line), NULL);
	}
	if (expansion)
		return (expand_str(heredoc_str, m));
	return (heredoc_str);
}
