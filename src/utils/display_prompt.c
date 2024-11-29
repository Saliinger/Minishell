/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 05:35:34 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *get_last_path(char *path)
{
    char *res;
    int i;
    int j;

    i = ft_strlen(path);
    while (path[i] != '/')
        i--;
    res = (char *)malloc(sizeof(char) * (ft_strlen(path) - i + 1));
    if (!res)
        return (NULL);
    j = 0;
    while (path[i])
    {
        res[j] = path[i];
        j++;
        i++;
    }
    res[j] = '\0';
    return (res);
}

char	*display_prompt(char *prompt, t_minishell *minishell)
{
	char	*path;
	char	*usr;
	char	*res;

	if (prompt)
		free(prompt);
	path = get_last_path(minishell->pwd);
	usr = getenv("LOGNAME");
	res = ft_strjoin(AINSI_BGREEN, usr);
	res = ft_strjoin(res, "@");
	res = ft_strjoin_frees1(res, "Femboys"); //fixme : env NAME=
	res = ft_strjoin_frees1(res, AINSI_RESET);
	res = ft_strjoin_frees1(res, ":");
	res = ft_strjoin_frees1(res, AINSI_BLUE);
	res = ft_strjoin_frees1(res, "~");
	res = ft_strjoin_frees1(res, path); //fixme parcours str, et si /home/$USER -> replace by ~
	res = ft_strjoin_frees1(res, AINSI_RESET);
	res = ft_strjoin_frees1(res, " ");
    free(path);
	return (res);
}
