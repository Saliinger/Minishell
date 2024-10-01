/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:35:28 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 15:38:28 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function need to check if the input syntax is ok to run before alloc
//
// check for single and double quote open
// check for multiple pipe ||
// check for redirection <<< 
//
//add a check for forbiden char like ; or others
//just when they're not in a flag

#include "../../include/minishell.h"

bool	quote_checker(char *in, char c)
{
	int	i = 0;
	int	flag = 0;

	while(in[i])
	{
		if (in[i] == c)
		{
			flag = 1;
			i++;
			while (in[i] && in[i] != c)
				i++;
			if (in[i] == c)
				flag = 0;
		}
		i++;
	}
	if (flag == 1)
		return (printf("Error syntax: the %c is not closed. Go fuck yourself\n", c), false);
	return (true);
}
// fix the quote_checker issue when a quote is inside a quote arg
bool	divider_checker(char *in, char c)
{
	int i = 0;

	while(in[i])
	{
		if (in[i] == c)
		{
			if (in[i + 1] == c && c == '|')
				return (printf("Error syntax: too many %c. Are really trying\n", c), false);
			if (in[i + 1] == c && in[i + 2] == c && (c == '<' || c == '>'))
				return (printf("Error syntax: too many %c. Are really trying\n", c), false);			
		}
		i++;
	}
	return (true);
}

bool	forbiden_checker(char *in, char c)
{
	return false;
}

bool	input_checker(char *in)
{
	if (divider_checker(in, '<') && quote_checker(in, '\'') && divider_checker(in, '>') && divider_checker(in, '|') && quote_checker(in, '"'))
		return (true);
	else
		return (false);
}
