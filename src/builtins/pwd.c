/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:48 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:29:49 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// display path / where i am

#include "../../include/minishell.h"
#include <unistd.h>

void	ft_pwd(t_minishell *minishell)
{
	char	path[PATH_MAX];

	getcwd(path, sizeof(path));
	printf("%s\n", path);
}
