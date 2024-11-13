/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:43:39 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/13 00:01:46 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_args(t_command_exec *c)
{	
	int	i;

	if (c->cmd_args)
	{
		printf("\tArguments (execve tab):\n");
		i = 0;
		while (c->cmd_args[i])
		{
			printf("\t\t[%d]:\t%s\n", i, c->cmd_args[i]);
			i++;
		}
		printf("\t\t[%d]:\t%p\n", i, c->cmd_args[i]);
	}
	else
		printf("%p\n", c->cmd_args);
}

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
	if (c->next)	
		print_body(c->next);
	else
	{
		printf("\n\n");
		while (--len > 0)
			printf("_");
		printf("\n");
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
		printf("#");
	printf("\n#-  %s  -#\n", display_name);
	while(++i < len)
		printf("#");
}

void	print_cmd_nodes(t_command_exec *c, char *display_name)
{
	printf("\n\n");
	print_display_name(display_name);
	print_body(c);
	return ;
}
