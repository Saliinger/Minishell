/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimmer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/12 17:06:35 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// trim the *in and put it in the struct t_command for other use

#include "../../include/minishell.h"

t_command *trim(char *in, char *in_command)
{
	t_command *command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->in = ft_strdup(in);
	command->arg = ft_split(in, ' ');
	command->command = ft_strdup(in_command);
	return (command);
}
