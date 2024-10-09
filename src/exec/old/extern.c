/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:00 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/09 15:30:24 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// execute extern function
//
// need to add the right path and parse the path in the env and check with access

#include "../../../include/minishell.h"

void	ft_extern(t_command *command, t_minishell *minishell)
{
	char	*path;
	pid_t	pid;

	path = ft_strjoin(PATH, command->command);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, command->arg, minishell->env) == -1)
		{
			//free_command(command);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	while (wait(NULL) > 0)
		;
	// free_command(command);
	free(path);
}
