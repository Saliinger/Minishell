/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:30 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/30 03:37:00 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static bool is_builtin(int id)
{
    if (id >= BUILTIN_ID_MIN) {
        if (id <= BUILTIN_ID_MAX)
            return (true);
    } else {
        if (0)
            return (true);
    }
	return (false);
}

static bool is_extern(int id)
{
	if (id == 0 || id == MINISHELL_ID)
		return (true);
	return (false);
}

static void exec(t_command_exec *c, t_minishell *m, t_infos *i)
{
	if (is_builtin(c->cmd_id))
		m->exit_status[0] = exec_builtin(c, m, i);
	else if(is_extern(c->cmd_id))
		i->last_pid = exec_extern(c, m, i);
	else
	{
		printerr("minishell: %s: %d: parsing err: unknown cmd_id = %d \n", __FILE__, __LINE__, c->cmd_id);
		m->exit_status[0] = 1;
	}
}

/**
 * brief : for each cmd in c,
 * will exec them as built ins if cmd has an id
 * else will exec it as an extern (execve in the child, and notes the pids in t_pids pids)
 * then waits for all the noted pids to be done and returns exit status of the last executed cmd
 * 
 * allocates & frees t_pids 
 */
int	exec_loop(t_command_exec **cmds, t_minishell *m, t_infos *i)
{
	int				err;
	t_command_exec	*c;
	t_command_exec	*next;

	c = *cmds;
	while (c)
	{
		err = open_cmd_fds(c, c->redir_fds);
		if (err)
			return (err);
		if (c->cmd_args && c->cmd_args[0])
			exec(c, m, i);
		next = c->next;
		free_t_command_exec_node(&c);
		c = next;
	}
	cmds = &c;
	return (get_exit_status(m, i));
}
