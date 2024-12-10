/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:06:59 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/10 15:32:05 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "imports.h"
# include "structure.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <sys/stat.h>

// CD
int		ft_cd(t_command_exec *command, t_minishell *minishell);
bool	is_symlink(const char *path);
char	*get_path(char *in, t_minishell *minishell);
char	*get_home(t_minishell *minishell);
char	*path_constructor(t_minishell *minishell, char *in);
char	*get_current_path(t_minishell *minishell);
int		change_pwd(t_minishell *minishell, char *in);
void	remove_path(char *dest);
void	add_path(char *dest, char *to_add);

// ECHO
int		ft_echo(t_command_exec *command);
void	echo_print(char **arg, bool eof, int i);
int		check_flag(char **arg);

// ENV
int		ft_env(t_minishell *minishell);

// EXIT
int		ft_exit(t_minishell *minishell, t_command_exec *command, bool fail);

// EXPAND
int		ft_expand(t_command_exec *command, t_minishell *minishell);

// PWD
int		ft_pwd(t_minishell *minishell);

// UNSET
int		ft_unset(t_command_exec *command, t_minishell *minishell);
int		count_var(char **var);
char	**new_env(t_minishell *minishell, int *to_remove, int nbr_of_line);

// EXPORT
int		ft_export(t_command_exec *command, t_minishell *minishell);
int		create_var(t_minishell *minishell, char *var);
int		delete_var(t_minishell *minishell, int line);
bool	check_var_equals(char *in);
bool	check_var_name(char *in);

#endif
