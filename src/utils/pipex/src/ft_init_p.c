/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:24:20 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/08/03 16:33:03 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	tab_ind_line_containing(char **tab, char *containing)
{
	int		i;

	i = 0;
	while (tab[i] != NULL && ft_strncmp(containing, tab[i], 4))
		i++;
	if (tab[i] == NULL)
		return (-1);
	return (i);
}

char	**get_p_paths(t_pipex *p)
{
	int		i;
	char	*line_paths;
	char	**result;

	i = tab_ind_line_containing(p->env, "PATH");
	if (i == -1)
		return (NULL);
	if (i < 0)
	{
		ft_close_fds_io(p);
		exit(ft_error("tab_ind_line_containing = -1\n", ERR_PARSE));
	}
	line_paths = ft_substr(p->env[i], 5, ft_strlen(p->env[i]));
	result = ft_split(line_paths, ':');
	free(line_paths);
	if (result == NULL)
	{
		ft_close_fds_io(p);
		exit(ft_error("ft_split(paths, ':') = NULL\n", ERR_PARSE));
	}
	return (result);
}

int	ft_init_p(t_pipex *p, int argc, char *argv[], char *env[])
{
	int		err;
	char	*path_infile;
	char	*path_outfile;

	err = 0;
	p->env = env;
	p->paths = get_p_paths(p);
	p->args = NULL;
	p->cmd = NULL;
	p->fds.infile = -1;
	p->fds.outfile = -1;
	path_infile = argv[1];
	path_outfile = argv[argc - 1];
	err = ft_open_fds_io(p, path_infile, path_outfile);
	if (err)
		return (ERR_OUTFILE);
	return (0);
}
