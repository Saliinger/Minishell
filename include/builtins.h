/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:06:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 13:34:47 by anoukan          ###   ########.fr       */
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
char	*path_constructor(t_minishell *minishell, char *in);
char	*get_current_path(t_minishell *minishell);
int		change_pwd(t_minishell *minishell, char *in);

// ECHO
int		ft_echo(t_command *command);
int     check_flag(char **arg);
void    echo_print(char **arg, bool eof);

// ENV
int		ft_env(t_minishell *minishell);

// EXIT
int		ft_exit(t_minishell *minishell, t_command *command, bool fail);

// EXPAND
// ne gere pas si l'expand est une fonction pour le moment c'est a faire
int	ft_expand(t_command *command, t_minishell *minishell);

// HEREDOC

// PWD
int		ft_pwd(t_minishell *minishell);

// UNSET
int	ft_unset(t_command *command, t_minishell *minishell);

// EXPORT
int		ft_export(t_command *command, t_minishell *minishell);

#endif
