/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:13:52 by ekrebs            #+#    #+#             */
/*   Updated: 2024/09/10 00:55:55 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h" 

# define IN		0
# define OUT	1

// time complexity could be improved by this being a hashmap
typedef struct		s_pids
{
	pid_t			pid;
	struct s_pids	*next;
}					t_pids;

//t_pids functions
t_pids	*pids_addfront(t_pids *pids, pid_t pid);
void	free_pids(t_pids *pids);
int		pids_size(t_pids *pids);

//FUNCTIONS LOCALISED TO EXEC
int		exec(t_command *c, t_minishell *m);
int		parent_waits(t_command *c, t_pids *pids, pid_t last_child_pid);
int		execve_command(t_command *c, t_minishell *m);
int		piper(t_command *cmds, t_minishell *m);

#endif