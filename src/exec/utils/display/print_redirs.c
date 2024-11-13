/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:52:06 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 00:13:29 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_redirs(t_redir *redir)
{
	while (redir)
	{
		//printf("Redirection Node %d:\n", i);
		printf("\t%s\t\t-\t", redir->redir);
		if (redir->type == R_IN_FILE)
			printf("R_IN_FILE");
		else if(redir->type == R_IN_HD)
			printf("R_IN_HD");
		else if(redir->type == R_OUT_FILE)
			printf("R_OUT_FILE");
		else if(redir->type == R_OUT_APPEND)
			printf("R_OUT_APPEND");
		printf(" (%d)\n", redir->type);
		redir = redir->next;
	}
	printf("\t%p\n", redir);
}