/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:43:39 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 17:50:54 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_args(t_command_exec *c)
{	
	int	i;

	if (c->cmd_args)
	{
		dprintf(STDERR_FILENO, "\tArguments (execve tab):\n");
		i = 0;
		while (c->cmd_args[i])
		{
			dprintf(STDERR_FILENO, "\t\t[%d]:\t%s\n", i, c->cmd_args[i]);
			i++;
		}
		dprintf(STDERR_FILENO, "\t\t[%d]:\t%p\n", i, c->cmd_args[i]);
	}
	else
		dprintf(STDERR_FILENO, "%p\n", c->cmd_args);
}

static void	print_body(t_command_exec *c)
{
	int len;

	len = dprintf(STDERR_FILENO, "\n________________t_command_exec: %p________________\n", c);
	dprintf(STDERR_FILENO, "\tCommand:   \t%s\n", c->cmd_args[0]);
	dprintf(STDERR_FILENO, "\tCommand ID:\t%d", c->cmd_id);
	if (c->cmd_id == 0)
		dprintf(STDERR_FILENO, " (extern)\n");
	else if (c->cmd_id >= 1 && c->cmd_id <= 10)
		dprintf(STDERR_FILENO, " (builtin)\n");
	else
		dprintf(STDERR_FILENO, " (error)\n");
	print_args(c);
	dprintf(STDERR_FILENO, "\tRedirection:\n");
	if (c->redir_files_llist)
		print_redirs(c->redir_files_llist);
	else
		dprintf(STDERR_FILENO, "\t%p\n", c->redir_files_llist);
	dprintf(STDERR_FILENO, "\tnext: %p \n", c->next);
	if (c->next)	
		print_body(c->next);
	else
	{
		dprintf(STDERR_FILENO, "\n\n");
		while (--len > 0)
			dprintf(STDERR_FILENO, "_");
		dprintf(STDERR_FILENO, "\n");
	}
	return ;
}

void	print_display_name(char *display_name)
{
	int len;
	int i;

	len = ft_strlen(display_name) + 8;
	i = len;
	while(i--)
		dprintf(STDERR_FILENO, "#");
	dprintf(STDERR_FILENO, "\n#-  %s  -#\n", display_name);
	while(++i < len)
		dprintf(STDERR_FILENO, "#");
}

void	print_cmd_nodes(t_command_exec *c, char *display_name)
{
	dprintf(STDERR_FILENO, "\n\n");
	print_display_name(display_name);
	print_body(c);
	return ;
}
