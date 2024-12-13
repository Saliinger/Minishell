/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:39:30 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 18:11:17 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static bool	is_builtin(int id)
{
	if (id >= BUILTIN_ID_MIN)
	{
		if (id <= BUILTIN_ID_MAX)
			return (true);
	}
	else
	{
		if (0)
			return (true);
	}
	return (false);
}

static bool	is_extern(int id)
{
	if (id == 0 || id == MINISHELL_ID)
		return (true);
	return (false);
}

/**
 * 
 * if the cmd is a solo builtin, it is executed as such.
 * if the cmd is not a builtin or if the cmd is piped, 
 * 									the pipeline is exectued as all externs.
 * 
 */
static void	exec(t_command_exec *c, t_minishell *m, t_infos *i, bool is_piped)
{
	if (is_piped == false && is_builtin(c->cmd_id))
	{
		i->last_cmd_type = CMD_BUILTIN;
		if (apply_redirections(c, i))
		{
			printerr("%s: %d: err applying redir\n", __FILE__, __LINE__);
			m->exit_status[0] = 1;
		}
		m->exit_status[0] = exec_builtin(c, m, i);
	}
	else if (is_piped == true || is_extern(c->cmd_id))
		i->last_pid = exec_extern(c, m, i);
	else
	{
		printerr("minishell: %s: %d: parsing err: unknown type ? = %d \n", \
												__FILE__, __LINE__, c->cmd_id);
		m->exit_status[0] = 1;
	}
	if (restore_std_fds(m->std_fds) == -1)
	{
		printerr("%s: %d: err restore std fds\n", __FILE__, __LINE__);
		m->exit_status[0] = 1;
	}
}

/**
 * brief : for each cmd in c,
 * will exec them as built ins if cmd has an id
 * else will exec it as an extern (execve in the child, and notes the pids 
 * 															in t_pids pids)
 * then waits for all the noted pids to be done and returns exit status 
 * 												of the last executed cmd
 * 
 * allocates & frees t_pids 
 */
int	exec_loop(t_command_exec **cmds, t_minishell *m, t_infos *i)
{
	int				err;
	t_command_exec	*c;
	t_command_exec	*next;
	bool			is_piped;

	c = *cmds;
	if (i->cmd_count > 1)
		is_piped = true;
	else
		is_piped = false;
	while (c)
	{
		next = c->next;
		err = open_cmd_fds(c, c->redir_fds);
		if (!err)
		{
			if (c->cmd_args && c->cmd_args[0])
				exec(c, m, i, is_piped);
		}
		free_t_command_exec_node(&c);
		c = next;
	}
	*cmds = c;
	return (get_exit_status(i));
}
