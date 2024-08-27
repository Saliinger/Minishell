/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:08 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/12 18:42:13 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parsing(char *str, t_minishell *minishell)
{
	t_command	*current;

	current = command_init(str);
	if (current)
		ft_exec(current, minishell);
	else
		printf("loli said: bitch it's not working\n");
}

// it just create the node for the command and start the exec
