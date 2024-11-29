/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:22 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 01:39:34 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_pwd(t_minishell *minishell)
{
	char	path[PATH_MAX];

	(void) minishell;
	getcwd(path, sizeof(path));
	printf("%s\n", path);
	return (0);
}
