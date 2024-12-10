/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:09:18 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 15:12:02 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	ft_close_pipes(int pipe_count, int ***pipes_tab_adr)
{
	int i;
	int err;
	int	**pipes;

	err = 0;
	pipes = *pipes_tab_adr;
	if (!pipes_tab_adr || !pipes)
		return (EXIT_SUCCESS);
	i = 0;
	while (i < pipe_count)
	{
		if (pipes[i])
		{
			err += ft_close(&pipes[i][0]);
			err += ft_close(&pipes[i][1]);
			ft_free((void **)&pipes[i]);
			if (err)
				return (printerr("%s: %d: err closing pipes", __FILE__, __LINE__), ERR);
		}
		i++;
	}
	ft_free((void **)pipes_tab_adr); 
	return (EXIT_SUCCESS);
}


int	create_all_pipes(int cmd_count, int ***pipes_out)
{
	int **pipes;
	int i;
	
	i = 0;
	if (cmd_count < 2)
		return (EXIT_SUCCESS);

	pipes = malloc((cmd_count - 1) * sizeof(int *));
	if (!pipes)
		return perror("malloc"), ERR;
	while (i < cmd_count - 1)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
			return (perror("#creating pipes: malloc"), ft_close_pipes(i, &pipes), ERR);
		if (pipe(pipes[i]) == -1)
			return (perror("#creapting pipes: pipe"), ft_close_pipes(i + 1, &pipes), ERR);
		i++;
	}
    *pipes_out = pipes;
    return (EXIT_SUCCESS);
}
