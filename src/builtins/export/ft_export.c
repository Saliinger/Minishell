/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:16 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 21:50:27 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char *extract_var(char *in)
{
    char *res;
    int len = 0;
    int i = 0;

    while(in[len] && in[len] != '=')
        len++;
    res = (char *) malloc(sizeof(char) * len + 1);
    if (!res)
        return (NULL);
    while (i < len)
    {
        res[i] = in[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

int manage_var(t_minishell *minishell, char *var)
{
    char *extracted;
    int line;
    int error;

    extracted = extract_var(var);
    if (!check_var_name(extracted) || !check_var_equals(var))
        return (printerr("checker error\n"), 1);
    line = get_env_var(minishell, extracted, ft_strlen(extracted));
    if (line == -1)
        error = create_var(minishell, var);
    else
    {
        error = delete_var(minishell, extracted);
        error += create_var(minishell, var);
    }
    return (error);
}

int	ft_export(t_command_exec *command, t_minishell *minishell)
{
    int i = 1;
    int error = 0;

	if (nbr_of_line(command->cmd_args) > 1)
    {
        while(command->cmd_args[i])
        {
            error = manage_var(minishell, command->cmd_args[i]);
            if (error >= 1)
            {
                perror("issue while creating the var\n");
                return (1);
            }
            i++;
        }
    }
    else
        ft_env(minishell);
    return (0);
}
