/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_effects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:16:46 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/25 10:50:51 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/signals.h"
/**
 * brief : Ctrl + \ effect when in mode heredoc
 *  : does nothing.
 */
void	sigeffect_heredoc_sigquit()
{
	g_sig = 0; //SIG_HANDLED;
}

/**
 * brief : Ctrl + D effect when in mode minishell
 *  : does nothing.
 */
void	sigeffect_minishell_sigquit()
{
	g_sig = 0; //SIG_HANDLED;
}
