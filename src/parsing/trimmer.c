/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimmer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/12 18:23:28 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// trim the *in and put it in the struct t_command for other use

#include "../../include/minishell.h"

t_command	*trim(char *in, char *in_command, bool builtin, int id)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->in = ft_strdup(in);
	command->arg = ft_split(in, ' ');
	command->command = ft_strdup(in_command);
	command->builtin = builtin;
	command->id = id;
	return (command);
}
