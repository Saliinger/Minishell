/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:50:44 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:50:45 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

int	count_var(char **var)
{
	int	i;

	i = 0;
	while (var[i])
		i++;
	return (i);
}
