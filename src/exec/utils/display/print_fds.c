/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:01:55 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 04:41:21 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	print_fds(int *fds, char* name, char *display_name)
{
	if (!fds)
		return ;
	print_display_name(display_name);
	ft_print_err("\n\t%s\n", name);
	ft_print_err("\t\t[%d ( IN)(RE)] %d\n", IN, fds[IN]);
	ft_print_err("\t\t[%d (OUT)(WE)] %d\n", OUT, fds[OUT]);
}