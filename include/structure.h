/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:06:50 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/07 23:14:34 by anoukan          ###   ########.fr       */
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
	e_redir				type;
	char				*redit;
}						t_redir;

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
	int					redirection_position;
	int					pipe_fds[2];
	int					pid;
	t_redir				*redirection; // ajout d'une struct pour creer le tableau de redir
	int					infile_fd;
	int					outfile_fd;
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

#endif
