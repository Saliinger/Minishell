/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/12 11:13:40 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_cd(t_command_exec *command, t_minishell *minishell)
{
	int		error;
	char	*path;

	path = get_path(command->cmd_args[1], minishell);
	if (!path)
		return (1);
	error = chdir(path);
	if (error == 0)
	{
		printf("Changed dir to %s\n", path);
		change_pwd(minishell, path);
	}
	else
		printf("Error changing directory");
	free(path);
	return (0);
}
