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
    while(in[len] != '=')
        len++;

}

int manage_var(t_minishell *minishell, char *var)
{
    char *extract_var;



}

int	ft_export(t_command_exec *command, t_minishell *minishell)
{
    int i = 0;
    int error = 0;
    char *ex_var;

	if (nbr_of_line(command->cmd_args) > 1)
    {
        while(command->cmd_args[i])
        {
            if (check_var(command->cmd_args[i]))
                error = manage_var(minishell, command->cmd_args);
            else
            {
                perror("var is not valid\n");
                return (1);
            }
            if (error == 1)
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
