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

int var_exist(char *name, t_minishell *minishell)
{
    int line;
    t_export_list *tmp;

    line = get_env_var(minishell, name, ft_strlen(name));
    tmp = find_export_node(name, minishell->exportList);
    printf("1\n");
    if (line == -1 && !tmp)
        return (0);
    else if (line == -1)
        return (1);
    return (2);
}

int export_handler(char *line, char *name, char *value, t_minishell *minishell)
{
    int status;

    status = var_exist(name, minishell);
    if (status == 0)
    {
        add_node_export(minishell->exportList, name, value);
        if (value)
            create_var(minishell, line);
    }
    else if (status == 1)
    {
        if (value)
        {
            modify_value(minishell->exportList, name, value);
            create_var(minishell, line);
        }
    }
    else
    {
        if (value)
        {
            modify_value(minishell->exportList, name, value);
            delete_var(minishell, get_env_var(minishell, name, ft_strlen(name)));
            create_var(minishell, line);
        }
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
            if (!check_name(name))
            {
                free(name);
                i++;
            }
            else
            {
                value = get_value_env(command->cmd_args[i]);
                export_handler(command->cmd_args[i], name, value, minishell);
                i++;
            }
        }
    }
    else
        print_export_list(minishell->exportList);
    return (0);
}
