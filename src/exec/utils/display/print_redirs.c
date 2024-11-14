/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:52:06 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/14 02:25:14 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_redirs(t_redir *redir)
{
	dprintf(STDERR_FILENO, "\t\t  p a t h       |          t y p e\n");
	while (redir)
	{
		dprintf(STDERR_FILENO, "\t\t%-10s", redir->redir);
		dprintf(STDERR_FILENO, "\t-   \t");
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
	dprintf(STDERR_FILENO, "\t\t%p\n", redir);
}