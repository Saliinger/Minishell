/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:52:06 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/29 06:00:20 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_redirs(t_redir *redir)
{
	//dprintf(STDERR_FILENO, "\t\t  p a t h       |          t y p e\n");
	while (redir)
	{
		dprintf(STDERR_FILENO, "\t\t%-10s\t-   \t", redir->redir);
		if (redir->type == R_IN_FILE)
			dprintf(STDERR_FILENO, "R_IN_FILE ");
		else if(redir->type == R_IN_HEREDOC)
			dprintf(STDERR_FILENO, "R_IN_HEREDOC  ");
		else if(redir->type == R_IN_HEREDOC_Q)
			dprintf(STDERR_FILENO, "R_IN_HEREDOC_Q");
		else if(redir->type == R_OUT_FILE_TRUNC)
			dprintf(STDERR_FILENO, "R_OUT_TRUNC");
		else if(redir->type == R_OUT_FILE_APPEND)
			dprintf(STDERR_FILENO, "R_OUT_APPEND");
		dprintf(STDERR_FILENO, " (%d)\n", redir->type);
		redir = redir->next;
	}
	dprintf(STDERR_FILENO, "\t\t%p\n", redir);
}