/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:26 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:50:48 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_unset(t_command_exec *command, t_minishell *minishell)
{
	int		*to_remove;
	int		nbr_of_var;
	int		j;
	char	*temp;
	int		temp_len;

	nbr_of_var = count_var(command->cmd_args + 1);
	to_remove = (int *)malloc(sizeof(int) * nbr_of_var);
	if (!to_remove)
		return (1);
	j = 0;
	while (command->cmd_args[j + 1])
	{
		temp = ft_strdup(command->cmd_args[j + 1]);
		temp_len = ft_strlen(temp);
		to_remove[j] = get_env_var(minishell, temp, temp_len);
		free(temp);
		j++;
	}
	minishell->env = new_env(minishell, to_remove, j);
	free(to_remove);
	return (0);
}
