/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:00 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/09 11:40:10 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_echo(t_command_exec *command)
{
    int i;
    char **cmd;

    cmd = command->cmd_args + 1;
    i = check_flag(cmd);
    if (i > 0)
        echo_print(cmd + i, false);
    else
        echo_print(cmd + i, true);
    return (0);
}
