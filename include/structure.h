/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:06:50 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/13 15:32:26 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

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

# include "imports.h"

// Structure
typedef struct s_redir
{
	t_enum_redir		type;
	char				*redir;
	struct s_redir		*next;
}						t_redir;

typedef struct s_command
{
	char				*in;
	char				*command;
	char				**arg;
	char				**clean_arg;
	int					id;
	struct s_command	*subcommand; 
	bool				builtin;
	bool				pipe;
	int					pipe_position;
	int					pipe_fds[2];
	int					pid;
	t_redir				*redirection;
	int					infile_fd;
	int					outfile_fd;
}						t_command;

typedef struct s_minishell
{
	char				**env;
	char				**hidden_env;
	char				**hidden_path;
	char				**paths;
	char				*pwd;
	char				*old_pwd;
	int					res_last_command;
	char				**hd;
}						t_minishell;

#endif
