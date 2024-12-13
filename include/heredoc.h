/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 04:30:06 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 08:16:13 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include "minishell.h"

char	*heredoc(char *key, t_minishell *m);

char	*get_env_value(char **env, const char *var);
char	*append_to_result(char *result, const char *start, size_t len);
size_t	find_next_dollar(const char *line, size_t start);
#endif