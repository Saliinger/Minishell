/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:58:08 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/11 20:36:19 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parsing(char *str)
{
	if (commands(str))
		printf("%s\n", str);
    else
        printf("loli said: bitch it's not a command\n");
}

