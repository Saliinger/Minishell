/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:21:16 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:49:59 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	is_symlink(const char *path)
{
	struct stat	path_stat;

	if (lstat(path, &path_stat) == -1)
	{
		perror("lstat");
		return (false);
	}
	if (S_ISLNK(path_stat.st_mode))
		return (true);
	else
		return (false);
}
