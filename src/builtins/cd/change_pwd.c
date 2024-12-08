/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:42:23 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/12 11:13:07 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	change_pwd(t_minishell *minishell, char *in)
{
	int		pwd_line;
	int		oldpwd_line;
	char	cwd[PATH_MAX];
	char	*path;

	pwd_line = get_env_var(minishell, "PWD=", 4);
	oldpwd_line = get_env_var(minishell, "OLDPWD=", 7);
	if (pwd_line == -1 || oldpwd_line == -1)
		return (1);
	if (!in)
	{
		getcwd(cwd, PATH_MAX);
		path = cwd;
	}
	else
		path = in;
	free(minishell->old_pwd);
	minishell->old_pwd = ft_strdup(minishell->pwd);
	free(minishell->env[oldpwd_line]);
	minishell->env[oldpwd_line] = ft_strjoin("OLDPWD=", minishell->old_pwd);
	free(minishell->pwd);
	minishell->pwd = ft_strdup(path);
	free(minishell->env[pwd_line]);
	minishell->env[pwd_line] = ft_strjoin("PWD=", path);
	return (0);
}
