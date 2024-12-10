/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_current_cmd_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:41:25 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 19:14:35 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

// static void	print_body(t_command_exec *c)
// {
// 	int len;

// 	len = dprintf(STDERR_FILENO, "\n________________t_command_exec: %p________________\n", c);
// 	dprintf(STDERR_FILENO, "\tCommand:   \t%s\n", c->cmd_args[0]);
// 	dprintf(STDERR_FILENO, "\tCommand ID:\t%d", c->cmd_id);
// 	if (c->cmd_id == 0)
// 		dprintf(STDERR_FILENO, " (extern)\n");
// 	else if (c->cmd_id >= 1 && c->cmd_id <= 10)
// 		dprintf(STDERR_FILENO, " (builtin)\n");
// 	else
// 		dprintf(STDERR_FILENO, " (error)\n");
// 	print_args(c);
// 	dprintf(STDERR_FILENO, "\tRedirection:\n");
// 	if (c->redir_files_llist)
// 		print_redirs(c->redir_files_llist);
// 	else
// 		dprintf(STDERR_FILENO, "\t%p\n", c->redir_files_llist);
// 	dprintf(STDERR_FILENO, "\tnext: %p \n", c->next);
// 	dprintf(STDERR_FILENO, "\n\n");
// 	while (--len > 0)
// 		dprintf(STDERR_FILENO, "_");
// 	dprintf(STDERR_FILENO, "\n");
// 	return ;
// }

void	print_current_cmd_node(t_command_exec *c, char *display_name)
{
	print_display_name(display_name);
	print_body(c);
}
