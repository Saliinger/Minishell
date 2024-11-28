/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:19:51 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 12:39:17 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/signals.h"

void	heredoc_signal_handler(int signal)
{
	if (signal == SIGINT)
		sigeffect_heredoc_sigint();
	else if (signal == SIGQUIT)
		sigeffect_heredoc_sigquit();
}

void	minishell_signal_handler(int signal)
{
	if (signal == SIGINT)
		sigeffect_minishell_sigint();
	else if (signal == SIGQUIT)
		sigeffect_minishell_sigquit();
}
