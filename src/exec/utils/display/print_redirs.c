/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:52:06 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 17:46:11 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_redirs(t_redir *redir)
{
	while (redir)
	{
		//dprintf(STDERR_FILENO, "Redirection Node %d:\n", i);
		dprintf(STDERR_FILENO, "\t%s\t\t-\t", redir->redir);
		if (redir->type == R_IN_FILE)
			dprintf(STDERR_FILENO, "R_IN_FILE");
		else if(redir->type == R_IN_HD)
			dprintf(STDERR_FILENO, "R_IN_HD");
		else if(redir->type == R_OUT_FILE)
			dprintf(STDERR_FILENO, "R_OUT_FILE");
		else if(redir->type == R_OUT_APPEND)
			dprintf(STDERR_FILENO, "R_OUT_APPEND");
		dprintf(STDERR_FILENO, " (%d)\n", redir->type);
		redir = redir->next;
	}
	dprintf(STDERR_FILENO, "\t%p\n", redir);
}