/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:41:23 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 00:12:54 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_redir(t_redir *redir)
{
	if (redir)
	{
		//printf("Redirection Node %d:\n", i);
		printf("\n\t%s\t\t-\t", redir->redir);
		if (redir->type == R_IN_FILE)
			printf("R_IN_FILE");
		else if(redir->type == R_IN_HD)
			printf("R_IN_HD");
		else if(redir->type == R_OUT_FILE)
			printf("R_OUT_FILE");
		else if(redir->type == R_OUT_APPEND)
			printf("R_OUT_APPEND");
		printf(" (%d)\n", redir->type);
	}
	else
		printf("\t%p\n", redir);	
}