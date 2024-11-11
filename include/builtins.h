/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:06:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/08 15:28:28 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "imports.h"
# include "structure.h"
# include <sys/stat.h>

// CD
int		ft_cd(t_command *command, t_minishell *minishell);
int		is_symlink(const char *path);
char	*get_path(char *in, t_minishell *minishell);
char	*get_home(t_minishell *minishell);
char	*path_constructor(char *in);

// ECHO
int		ft_echo(t_minishell *minishell, t_command *command);

// ENV
int		ft_env(t_minishell *minishell);

// EXIT

// EXPAND

// HEREDOC

// PWD
int		ft_pwd(t_minishell *minishell);

// UNSET

#endif
