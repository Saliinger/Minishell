/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:41:23 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/29 06:02:30 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_redir(t_redir *redir)
{
	if (redir)
	{
		//dprintf(STDERR_FILENO, "Redirection Node %d:\n", i);
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
	}
	else
		dprintf(STDERR_FILENO, "\t%p\n", redir);
}