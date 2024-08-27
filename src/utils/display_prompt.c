/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:34:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	display_prompt(char **prompt, t_minishell *minishell)
{
	char	buffer[4096 + 1];
	char	*path;
	char	*usr;
	char	*pc;

	path = minishell->pwd;
	usr = getenv("LOGNAME");
	*prompt = ft_strjoin(usr, "@");
	*prompt = ft_strjoin_frees1(*prompt, "Femboys");
	*prompt = ft_strjoin_frees1(*prompt, ":~");
	*prompt = ft_strjoin_frees1(*prompt, path);
	*prompt = ft_strjoin_frees1(*prompt, " ");
}
