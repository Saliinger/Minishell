/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/27 13:24:39 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# include "imports.h"
# include "parsing.h"
# include "structure.h"

// FREE
void		free_nullterm_tab(char **tab);
void		free_t_command(t_command *cmds);
void		free_t_minishell(t_minishell *m);
void		free_minishell(t_minishell *minishell);
void		free_command(t_command *command);

int			ft_close_fd(int *fd);

// EXEC
int			ft_exec(t_command *c, t_minishell *m);
// transitionning out :
void		builtin_slector(t_command *cmd, t_minishell *m);
void		old_ft_exec(t_command *command, t_minishell *minishell);
void		ft_extern(t_command *command, t_minishell *minishell);

// PARSING
t_command	*command_init(char *in);
void		parsing(char *str, t_minishell *minishell);
t_command	*trim(char *in, char *in_command, bool builtin, int id);
bool		input_checker(char *in);
t_redir		*extract_redir(char **in);
char		**clean_arg(char **arg, t_minishell *minishell);
char		**relexer(char **in);

// Divider for parsing
int			check_pipe(char *in);

// UTILS
char		*display_prompt(char *prompt, t_minishell *minishell);
void		sighandler(int sig);
char		**get_env(char **env);
bool		checker_command(char *in, char *command);
int			nbr_of_line(char **env);

void		free_env(char **env);

// Split Element
size_t		ft_countword(const char *s, char c);
int			ft_split_free(char **dest);
void		ft_split_write_word(char *dest, const char *src, int start,
				int end);
char		**split_element(char const *s, char c);

// ENV_UTILITY
int			get_env_var(t_minishell *minishell, char *var, int len);
void		change_pwd(t_minishell *minishell);

// Debug
void		ft_print(char **s, int i);
void		ft_print_redir(t_redir *list);
void		print_command(t_command *command);

#endif

// get current dir si il n'y a pas d'env au debut
// bien up pwd path
//
