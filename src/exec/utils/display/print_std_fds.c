/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_std_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:32:43 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/02 04:57:05 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_std_fds(int *fds, char *display_name)
{
	int	i;

	if (!fds)
		return ;
	i = 0;
	printf("\t#- %s -#", display_name);
	printf("\n\tstd_fds\n");
	while(i < 2)
	{
		printf("\t\t[%d] %d\n", i, fds[i]);
		i++;
	}
}