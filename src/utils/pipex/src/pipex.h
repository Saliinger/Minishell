/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:43:27 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/08/03 21:22:15 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include "errors.h"
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_fd_io
{
	int		infile;
	int		outfile;
}	t_fd_io;

typedef struct s_pipex
{
	char	**env;
	char	**paths;
	char	**args;
	char	*cmd;
	int		pipefd[2];
	t_fd_io	fds;
}	t_pipex;

int		ft_init_p(t_pipex *p, int argc, char *argv[], char *env[]);
int		ft_pipex(t_pipex *p, char *argv[], int argc);
int		ft_exec_command(t_pipex *p, char *argv[], int i);
int		ft_parent_waits(t_pipex *p, int i, pid_t pid);

char	**ft_custom_split(char const *str, char c);

int		ft_open_fds_io(t_pipex *p, char *infile, char *outfile);
int		ft_close_fds_io(t_pipex *p);

int		ft_close_fd(int *fd);
void	ft_free_tab(char **tab);
void	ft_free_paths(t_pipex *p);
void	ft_free_args(t_pipex *p);
#endif
