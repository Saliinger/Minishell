/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/08 14:37:14 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*display_prompt(char *prompt, t_minishell *minishell)
{
	char	buffer[4096 + 1];
	char	*path;
	char	*usr;
	char	*pc;
	char	*res;

	if (prompt)
		free(prompt);
	path = minishell->pwd;
	usr = getenv("LOGNAME");
	res = ft_strjoin(usr, "@");
	res = ft_strjoin_frees1(res, "Femboys");
	res = ft_strjoin_frees1(res, ":~");
	res = ft_strjoin_frees1(res, path);
	res = ft_strjoin_frees1(res, " ");
	return (res);
}
