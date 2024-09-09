/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:43:35 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/08/03 21:13:49 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	p;
	int		file_err;
	int		pip_err;

	file_err = 0;
	pip_err = 0;
	if (argc <= 5)
		return (ft_printf("Error aaargs\n"), ERR_ARGS);
	file_err = ft_init_p(&p, argc, argv, env);
	pip_err = ft_pipex(&p, argv, argc);
	ft_free_paths(&p);
	if (file_err)
		return (file_err);
	if (pip_err)
		return (pip_err);
	return (0);
}
