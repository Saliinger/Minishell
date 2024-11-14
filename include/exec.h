/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:13:52 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/14 02:24:25 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# define IN		0
# define OUT	1

#define HEREDOC	-2


typedef enum e_cmd_type
{
	CMD_BUILTIN = 1,
	CMD_EXTERN,
} t_cmd_type;

typedef struct s_pids
{
	pid_t			pid;
	struct s_pids	*next;
}					t_pids;

typedef struct s_pids_info
{
	t_pids	*pids_list;
	pid_t	last_pid;
}			t_pids_info;

/**
typedef struct s_redir
{
	t_enum_redir		type;
	char				*redir;
	struct s_redir		*next;
}						t_redir;
 */

typedef struct s_command_exec
{
	int						cmd_id;				//init me to 0,		//fill me if builtin with the builtin id, else 0 if not builtin
	char					**cmd_args;			//init me to NULL	//file me with the execve tab
	t_redir					*redir_files_llist; //init me to NULL
	char					*last_heredoc_str;	//init me to NULL, 
	int						pipe_fds[2];		//init as a tab of -1,	//parsing doesnt care about that
	int						redir_fds[2];		//init as a tab of -1,	//parsing doesnt care about that
	struct s_command_exec	*next;				//init me to NULL
}		t_command_exec;



// FUNCTIONS LOCALISED TO EXEC
int		exec_builtin(t_command_exec *c, t_minishell *m, t_cmd_type *last_cmd_type);
int	 	exec_cmds(t_command_exec *cmds, t_minishell *m, int* std_fds);
pid_t	exec_extern(t_command_exec *cmds, t_minishell *m, t_pids_info *p, t_cmd_type *last_cmd_type);
void	execve_command(t_command_exec *c, t_minishell *m, t_pids *pids);
int		open_cmds_fds(t_command_exec *cmds, int *fds_last_redir);
int		set_redirections(t_command_exec *cmd, t_minishell *m, int *std_fds, bool *am_first_cmd);
int		get_exit_status(t_cmd_type last_cmd_type, t_pids_info externs_pids_infos, int builtin_exit_status);
int		open_cmd_fds(t_command_exec *cmd, int *fds_last_redir, t_minishell *m);
int		restore_std_fds(int *std_fds);


//UTILS
//parsing_restruct
int		parsing_restruct(t_command **o, t_command_exec **c);
int		restruct_stealing_from_old(t_command **old, t_command_exec **c);
void	restruct_discarding_old(t_command **o);
void	print_parsing_restruct(t_command_exec *command, char *display_name);

//repasr redir files llist
int		reparse_redir_files_llist(t_command_exec *c);

// t_pids functions
t_pids	*pids_addfront(t_pids *pids, pid_t pid);
void	free_pids(t_pids *pids);
int		pids_size(t_pids *pids);

int		ft_close(int *fd);
int		ft_dup2(int fd, int fd2);
int		ft_dup(int fd);

void	ft_free_nullterm_tab(char ***ptab);
void	free_t_command_exec(t_command_exec **c);
void	ft_free_t_redir(t_redir **r);
void	ft_free(void **add);

char	*ft_resolve_heredoc(char *key, t_minishell *m);

void	print_std_fds(int *fds, char *display_name);
void	print_display_name(char *display_name);
void	print_current_cmd_node(t_command_exec *c, char *display_name);
void	print_redir(t_redir *redir);
void	print_redirs(t_redir *redir);
void	print_args(t_command_exec *c);
void	print_cmd_nodes(t_command_exec *c, char *display_name);
#endif