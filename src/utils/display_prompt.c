/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 05:22:18 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*display_prompt(char *prompt, t_minishell *minishell)
{
	char	*path;
	char	*usr;
	char	*res;

	if (prompt)
		free(prompt);
	path = minishell->pwd;
	usr = getenv("LOGNAME");
	res = ft_strjoin(AINSI_BGREEN, usr);
	res = ft_strjoin(res, "@");
	res = ft_strjoin_frees1(res, "Femboys"); //fixme
	res = ft_strjoin_frees1(res, AINSI_RESET);
	res = ft_strjoin_frees1(res, ":");
	res = ft_strjoin_frees1(res, AINSI_BLUE);
	res = ft_strjoin_frees1(res, "~");
	res = ft_strjoin_frees1(res, path);
	res = ft_strjoin_frees1(res, AINSI_RESET);
	res = ft_strjoin_frees1(res, " ");
	return (res);
}
