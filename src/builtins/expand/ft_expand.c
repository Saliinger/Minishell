/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:13 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 01:44:17 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// need to print the env var

int	ft_expand(t_command_exec *command, t_minishell *minishell)
{
    int i;
    char *temp;
    int temp_len;
    int line;

    i = 0;
    while (command->cmd_args[i])
    {
        temp = ft_strdup(command->cmd_args[i] + 1);
        temp_len = ft_strlen(temp);
        line = get_env_var(minishell, temp, temp_len);
        if (line == -1)
            fprintf(stderr, "var doesn't exist");
        else
        {
            fprintf(stderr, "%s", minishell->env[line]);
            if (command->cmd_args[i + 1])
                fprintf(stderr, " ");
        }
        free(temp);
        i++;
    }
	return (0);
}
