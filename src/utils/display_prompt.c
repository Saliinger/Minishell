/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/09 15:52:24 by anoukan          ###   ########.fr       */
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
	res = ft_strjoin(usr, "@");
	res = ft_strjoin_frees1(res, "Femboys");
	res = ft_strjoin_frees1(res, ":~");
	res = ft_strjoin_frees1(res, path);
	res = ft_strjoin_frees1(res, " ");
	return (res);
}
