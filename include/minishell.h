/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/11 15:12:06 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft/libft.h"
# include "errors.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

// Defines
# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"
# define HD "<<"
# define EXPAND "$"

// Define path
# define PATH "/bin/"

// Define ID
# define ECHO_ID 1
# define CD_ID 2
# define PWD_ID 3
# define EXPORT_ID 4
# define UNSET_ID 5
# define ENV_ID 6
# define EXIT_ID 7
# define NB_BUILTINS 8
# define HD_ID 9
# define EXPAND_ID 10

// Structure
typedef struct s_command
{
	char				*in;
	char				*command;
	char				**arg;
	int					id;
	struct s_command	*subcommand;
	bool				builtin;
	bool				pipe;
	int					pipe_position;
	bool				redirection;
	int					redirection_position;
	int					pipe_fds[2];
	int					pid;
	// new 		//init me at -1
	int					infile_fd;
	int					outfile_fd;
	// new 		//init me to -1,
	// fill me if cmd takes infile int outfile_fd;
	// new 		//init me to -1,
	// fill me if cmd takes outfile int pid;       // new		//init me to -1,
}						t_command;

/*
typedef struct s_command
{
	char				*cmd;
	char				**cmd_args;
	int					cmd_id;
	struct s_command	*next;
	int					pipe_fds[2];	//new 		//init me at -1
	int					infile_fd; 		//new 		//init me to -1,
													fill me if cmd takes infile
	int					outfile_fd; 	//new 		//init me to -1,
												fill me if cmd takes outfile
	int					pid;			//new		//init me to -1,
}						t_command;
*/

typedef struct s_minishell
{
	char				**env;
	char				**hidden_env;
	char				**hidden_path;
	// the hidden path is for the no env setup
	// will this concern me, or is it just a parsing/prompt thing ?
	// genq (echo and $?)
	char				**paths;
	// new	// init me extract me from env (line starting by PATHS),
	// then (split me on token ':')
	//->needed for exec cmd
	char				*builtins_paths[NB_BUILTINS];
	// new	// init me fill me with the path to each builtin, builtins_paths[id]
	//			-> needed for exec builtins
	char				*pwd;
	char				*old_pwd;
	int					res_last_command;
	char				**hd;
}						t_minishell;

// FREE
void					free_nullterm_tab(char **tab);
void					free_t_command(t_command *cmds);
void					free_t_minishell(t_minishell *m);
void					free_minishell(t_minishell *minishell);
void					free_command(t_command *command);


int						ft_close_fd(int *fd);

// EXEC
int						ft_exec(t_command *c, t_minishell *m);
// transitionning out :
void					builtin_slector(t_command *cmd, t_minishell *m);
void					old_ft_exec(t_command *command, t_minishell *minishell);
void					ft_extern(t_command *command, t_minishell *minishell);

// Builtins
void					ft_pwd(t_minishell *minishell);
void					ft_env(t_minishell *minishell);
void					ft_echo(t_minishell *minishell, t_command *command);
void					ft_cd(t_command *command, t_minishell *minishell);
void					ft_export(t_command *command, t_minishell *minishell);
void					ft_unset(t_command *command, t_minishell *minishell);
void					ft_heredoc(t_command *command, t_minishell *minishell);
void					exit_shell(t_minishell *minishell, t_command *command, bool fail);
void					ft_expand(t_command *command, t_minishell *minishell);


// PARSING
t_command				*command_init(char *in);
void					parsing(char *str, t_minishell *minishell);
t_command				*trim(char *in, char *in_command, bool builtin, int id);
bool					input_checker(char *in);
// Divider for parsing
int						check_pipe(char *in);

// UTILS
char					*display_prompt(char *prompt, t_minishell *minishell);
void					sighandler(int sig);
char					**get_env(char **env);
bool					checker_command(char *in, char *command);
int						nbr_of_line(char **env);

void					free_env(char **env);

// Split Element
size_t					ft_countword(const char *s, char c);
int						ft_split_free(char **dest);
void					ft_split_write_word(char *dest, const char *src,
							int start, int end);
char					**split_element(char const *s, char c);

// ENV_UTILITY
int						get_env_var(t_minishell *minishell, char *var, int len);
void					change_pwd(t_minishell *minishell);

// Debug
void					ft_print(char **s, int i);

#endif

// get current dir si il n'y a pas d'env au debut
// bien up pwd path
//
