/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:01:07 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/01 13:01:07 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	change_pwd(t_minishell *minishell)
{
	int		pwd_line;
	int		oldpwd_line;
	char	cwd[PATH_MAX];

	pwd_line = get_env_var(minishell, "PWD=", 4);
	oldpwd_line = get_env_var(minishell, "OLDPWD=", 7);
	if (pwd_line == -1 || oldpwd_line == -1)
		return ;
	free(minishell->old_pwd);
	minishell->old_pwd = ft_strdup(minishell->pwd);
	free(minishell->pwd);
	getcwd(cwd, sizeof(cwd));
	minishell->pwd = ft_strdup(cwd);
	free(minishell->env[pwd_line]);
	minishell->env[pwd_line] = ft_strjoin("PWD=", cwd);
	free(minishell->env[oldpwd_line]);
	minishell->env[oldpwd_line] = ft_strjoin("OLDPWD=", minishell->old_pwd);
}
