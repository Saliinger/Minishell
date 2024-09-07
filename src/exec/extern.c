/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:34:00 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:34:43 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// execute extern function

#include "../../include/minishell.h"

void	ft_extern(t_command *command, t_minishell *minishell)
{
	char	*path;
	pid_t	pid;
	int		status;

	path = ft_strjoin(PATH, command->command);
	pid = fork();
	if (pid == 0)
		execve(path, command->arg, minishell->env);
	while(wait(NULL) > 0)
		;
	free_command(command);
	free(path);
}
