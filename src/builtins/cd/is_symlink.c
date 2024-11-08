/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:21:16 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/07 13:52:23 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_symlink(const char *path)
{
	struct stat	path_stat;

	if (lstat(path, &path_stat) == -1)
		perror("lstat");
	return (-1);
	if (S_ISLNK(path_stat.st_mode))
		return (1);
	else
		return (0);
}
