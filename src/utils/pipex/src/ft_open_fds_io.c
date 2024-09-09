/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fds_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:50:57 by ekrebs            #+#    #+#             */
/*   Updated: 2024/08/03 18:33:52 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_fd_infile(t_pipex *p, char *infile)
{
	int	err;
	int	err_access;

	err = 0;
	err_access = 0;
	err_access = access(infile, F_OK);
	if (!err_access)
	{
		err_access = access(infile, R_OK);
		if (err_access)
			ft_printf("cannot open %s: Permission denied\n", infile);
		else
			p->fds.infile = open(infile, O_RDONLY);
	}
	else
		ft_printf("cannot open %s: No such file\n", infile);
	if (err_access || p->fds.infile == -1)
	{
		err = ERR_OPEN;
	}
	if (err || err_access)
		return (0);
	return (0);
}

static int	open_fd_outfile(t_pipex *p, char *outfile)
{
	int	err;
	int	err_access;

	err = 0;
	err_access = 0;
	err_access = access(outfile, F_OK);
	if (!err_access)
	{
		err_access = access(outfile, W_OK);
		if (err_access)
		{
			ft_printf("cannot create %s: Permission denied\n", outfile);
			return (ERR_OUTFILE);
		}
	}
	p->fds.outfile = open(outfile, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (p->fds.outfile == -1)
	{
		err = ERR_OPEN;
		ft_close_fd(&p->fds.infile);
	}
	if (err)
		return (ERR_OPEN);
	return (0);
}

int	ft_open_fds_io(t_pipex *p, char *infile, char *outfile)
{
	int	err;

	err = 0;
	err += open_fd_infile(p, infile);
	err += open_fd_outfile(p, outfile);
	if (err)
		return (ERR_OUTFILE);
	return (0);
}
