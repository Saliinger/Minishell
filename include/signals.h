/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:22:20 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 04:33:15 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <stdlib.h>
# include "minishell.h"
# include <signal.h>
# include <unistd.h>

#define NO_SIG 0

extern volatile sig_atomic_t	g_sig;
int		set_signals_to_minishell(void);
int		set_signals_to_default(void);
int		set_signals_to_ignore(void);
int		set_signals_to_heredoc(void);

void	minishell_signal_handler(int signal);
void	heredoc_signal_handler(int signal);

void	sigeffect_heredoc_sigint(void);
void	sigeffect_minishell_sigint(void);
void	sigeffect_heredoc_sigquit(void);
void	sigeffect_minishell_sigquit(void);

#endif