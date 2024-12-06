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

bool check_name(char *name)
{
    int i = 0;

    if (ft_isalnum(name[i])|| name[i] == '_')
        i++;
    while (name[i])
    {
        if (!ft_isalpha(name[i]) || name[i] ==  '_')
            return (false);
        i++;
    }
    return (true);
}

bool var_exist(char *name, t_minishell *minishell)
{
    int line;

    line = get_env_var(minishell, name, ft_strlen(name));
    if (line  == -1)
        return (false);
    return (true);
}

int export_handler(char *line, char *name, char *value, t_minishell *minishell)
{
    if (value)
    {
        if (var_exist(name, minishell))
        {
            modify_value(minishell->exportList, name, value);
            delete_var(minishell, get_env_var(minishell, name, ft_strlen(name)));
            create_var(minishell, line);
        }
        else
        {
            add_node_export(minishell->exportList, name, value);
            create_var(minishell, line);
        }
    }
    else
    {
        add_node_export(minishell->exportList, name, value);
    }
    merge_sort(minishell->exportList);
    return (0);
}

int	ft_export(t_command_exec *command, t_minishell *minishell)
{
    int i = 1;
    char *name;
    char *value;

    ft_print(command->cmd_args, 0);
    if (nbr_of_line(command->cmd_args) > 1)
    {
        while (command->cmd_args[i])
        {
            name = get_name_env(command->cmd_args[i]);
            if (!check_name(name)) {
                free(name);
                i++;
            }
            else
            {
                value = get_value_env(command->cmd_args[i]);
                if (!value)
                    // add var only to the export list
                    export_handler(command->cmd_args[i], name, NULL, minishell);
                else
                    // add var to the export list && minishell->env
                    export_handler(command->cmd_args[i], name, value, minishell);
            }
        }
    }
    else
        print_export_list(minishell->exportList);
    return (0);
}
