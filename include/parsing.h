/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:07:28 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 17:37:04 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_minishell t_minishell;


char		**relexer(char **in);
char **expand_in(char **arg, t_minishell *minishell);
// PARSING
t_command	*command_init(char *in);
t_command	*parsing(char *str, t_minishell *minishell);
t_command	*trim(char *in, char *in_command, bool builtin, int id);
bool		input_checker(char *in);
t_redir		*extract_redir(char **in);
char		**clean_arg(char **arg, t_minishell *minishell);

// Divider for parsing
int			check_pipe(char *in);

#endif
