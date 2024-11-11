/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 11:47:04 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_cd(t_command *command, t_minishell *minishell)
{
	int		error;
	char	*path;

	path = get_path(command->arg[1], minishell);
	if (!path)
		return (1);
	error = chdir(path);
	if (error == 0)
	{
		printf("Changed dir to %s\n", path);
		change_pwd(minishell);
	}
	else
		printf("Error changing directory");
	if (path)
		free(path);
	return (0);
}
