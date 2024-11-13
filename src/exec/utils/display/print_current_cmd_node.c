/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_current_cmd_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:41:25 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 00:01:21 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

static void	print_body(t_command_exec *c)
{
	int len;

	len = printf("\n________________t_command_exec: %p________________\n", c);
	printf("\tCommand:   \t%s\n", c->cmd_args[0]);
	printf("\tCommand ID:\t%d\n", c->cmd_id);
	print_args(c);
	printf("\tRedirection:\n");
	if (c->redir_files_llist)
		print_redirs(c->redir_files_llist);
	else
		printf("\t%p\n", c->redir_files_llist);
	printf("\tnext: %p \n", c->next);
	printf("\n\n");
	while (--len > 0)
		printf("_");
	printf("\n");
	return ;
}

void	print_current_cmd_node(t_command_exec *c, char *display_name)
{
	print_display_name(display_name);
	print_body(c);
}
