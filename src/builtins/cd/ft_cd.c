/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:53:53 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/30 10:19:13 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_cd(t_minishell *minishell, t_command *command)
{
	char *path;

	if (!command->clean_arg[1] || command->clean_arg[1][0])
	{
		path = 
	}
	chdir(command->clean_arg[1]);

	return (0);
}
