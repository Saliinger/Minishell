/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/01 14:39:46 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft/libft.h"
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

// Structure
typedef struct s_command
{
	char				*command;
	char				*in;
	char				**arg;
	struct s_command	*pipe_command;
	bool				builtin;
	int					id;
	bool				pipe;
}						t_command;

typedef struct s_minishell
{
	char				**env;
	char				*pwd;
	char				*old_pwd;
	int					res_last_command;
}						t_minishell;

// EXEC
void					builtin_slector(t_command *command,
							t_minishell *minishell);
void					ft_exec(t_command *command, t_minishell *minishell);
void					ft_extern(t_command *command, t_minishell *minishell);

// Builtins
void					ft_pwd(t_minishell *minishell);
void					ft_env(t_minishell *minishell);
void					ft_echo(t_command *command);
void					ft_cd(t_command *command, t_minishell *minishell);

// PARSING
t_command				*command_init(char *in);
void					parsing(char *str, t_minishell *minishell);
t_command				*trim(char *in, char *in_command, bool builtin, int id);

// UTILS
void					display_prompt(char **prompt, t_minishell *minishell);
void					sighandler(int sig);
void					exit_shell(bool fail);
char					**get_env(char **env);
bool					checker_command(char *in, char *command);
void					free_command(t_command *command);
int						nbr_of_line(char **env);
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
