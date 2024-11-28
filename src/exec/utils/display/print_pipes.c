/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:24:36 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 04:41:28 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_pipes(int **pipes, int pipe_count, char *name)
{
	int	i;

	i = 0;
	print_display_name(name);
	if (!pipes)
	{
		ft_print_err("%p\n", pipes);
		return ;
	}
	while (i < pipe_count)
	{
		if (pipes[i])
		{
			ft_print_err("#\tpipes[%d]\n", i);
			if (pipes[i][0])
				ft_print_err("#\t\tpipes[%d][0 R] = %d\n", i, pipes[i][0]);
			else
				ft_print_err("#\t\t!pipes[%d][0 R]\n", i);
			if (pipes[i][1])
			{

				ft_print_err("#\t\tpipes[%d][1 W] = %d\n", i, pipes[i][1]);
			}
			else
				ft_print_err("#\t\t!pipes[%d][1 W]\n", i);
		}
		else
			ft_print_err("#\t!pipes[%d]\n", i);
		i++;
	}
	ft_print_err("#done.\n\n");
}