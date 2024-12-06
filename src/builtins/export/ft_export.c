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

// export != env = trie ordre alphabetique
// affiche var pas initialise

char *extract_var(char *in)
{
    char *res;
    int i = 0;

    int len = 0;
    while(in[len] != '=')
        len++;
    res = (char *) malloc(sizeof(char) * len + 1);
    if (!res)
        return (NULL);
    while (len > i)
    {
        res[i] = in[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char *check_var(char *var)
{
    char *ex_var;

    if (check_var_equals(var) == false)
        return (printf("var equals err\n"), NULL);
    ex_var = extract_var(var);
    printf("ex var: %s\n", ex_var);
    if (check_var_name(ex_var) == false)
        return (printf("var name err\n"), free(ex_var), NULL);
    return (ex_var);
}

int manage_var(t_minishell *minishell, char *var)
{

    int line = 0;
    int error = 0;
    char *ex_var;

    ex_var = check_var(var);
    if (ex_var == NULL)
        return (1);
    line = get_env_var(minishell, ex_var, ft_strlen(ex_var));
    if (line == -1)
        error += create_var(minishell, var);
    else
    {
        error += delete_var(minishell, line);
        error += create_var(minishell, var);
    }
    return (error);
}

int	ft_export(t_command_exec *command, t_minishell *minishell)
{
    int i = 1;
    int error = 0;

    ft_print(command->cmd_args, 0);
    if (nbr_of_line(command->cmd_args) > 1) {
        while (command->cmd_args[i]) {
            error = manage_var(minishell, command->cmd_args[i]);
            if (error >= 1) {
                perror("issue while creating the var\n");
                return (1);
            }
            i++;
        }
    }
    else
        print_export_list(minishell->exportList);
    return (0);
}
