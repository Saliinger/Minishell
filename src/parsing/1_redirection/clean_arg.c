/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:13:49 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/09 18:27:07 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static bool	is_redirection(char *str)
{
        return ft_strcmp(str, "<<") == 0 || ft_strcmp(str, ">>") == 0 ||
           ft_strcmp(str, "<") == 0 || ft_strcmp(str, ">") == 0;
}

char	**clean_arg(char **arg)
{
	char	**res;
	int		i;

	i = 0;
    res = NULL;
	while (arg[i])
	{
        if (is_redirection(arg[i]) && arg[i + 1])
            i += 2;
        else
        {
            res = add_line(res, arg[i]);
            i++;
        }
	}
    ft_print(res, 0);
	return (res);
}
