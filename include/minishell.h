/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:22:12 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/12 17:11:56 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <signal.h>
# include <stdio.h>

// Defines
# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"
# define LS "ls"
//# define
# define PATH "/bin/"

// Structure
typedef struct s_command
{
	char				*command;
	char				*in;
	char				**arg;
	struct s_command	*pipe_command;
}						t_command;

typedef struct s_minishell
{
	char				**env;
}						t_minishell;

// EXEC

// Builtins
void    ft_pwd(void);
// PARSING
t_command				*command_init(char *in);
void					parsing(char *str);
t_command				*trim(char *in, char *in_command);

// UTILS
void					display_prompt(char **prompt);
void					sighandler(int sig);
void					exit_shell(bool fail);
char                    **get_env(char **env);

#endif
