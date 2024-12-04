/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:50:14 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/30 16:11:25 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void print_line(char *line)
{
    int i;
    i = 0;
    while (line[i])
    {
        printf("%c", line[i]);
        i++;
    }
}

void	echo_print(char **arg, bool eof, int i)
{
	while (arg[i])
	{
        print_line(arg[i]);
		if (arg[i + 1])
			printf(" ");
		i++;
	}
	if (eof == true)
		printf("\n");
}
