/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m0rgenstern <m0rgenstern@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:43:35 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/08/02 16:02:56 by m0rgenstern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	p;
	int		file_err;
	int		pip_err;

	file_err = 0;
	pip_err = 0;
	if (argc != 5)
		return (ft_printf("Error args\n"), ERR_ARGS);
	file_err = ft_init_p(&p, argc, argv, env);
	pip_err = ft_pipex(&p, argv, argc);
	ft_free_paths(&p);
	if (file_err)
		return (file_err);
	if (pip_err)
		return (pip_err);
	return (0);
}
