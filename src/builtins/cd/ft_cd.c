/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:49:49 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_cd(t_command_exec *command, t_minishell *minishell)
{
	int		error;
	char	*path;

	path = get_path(command->cmd_args[1], minishell);
	printerr("path: %s\n", path);
	if (!path)
		return (1);
	error = chdir(path);
	if (error == 0)
	{
		printerr("Changed dir to %s\n", path);
		change_pwd(minishell, path);
	}
	else
		printerr("Error changing directory\n");
	free(path);
	return (0);
}
