/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:54:26 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/11 01:43:53 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// this function is use to delete existing var in env
// it can delete multiple var at the same time
// (gonna make it after the base works)
// to add the multiple var i am gonna use a *int to store all the
// existing var if one of them doesn't exist just return an error

static char	**new_env(char **current_env, int var_line)
{
	int		i;
	int		j;
	char	**new_env;

	new_env = (char **)malloc(sizeof(char) * nbr_of_line((current_env)-1));
	if (!new_env)
		return (NULL);
	i = 0;
	j = 0;
	while (current_env[i])
	{
		if (i != var_line)
		{
			new_env[j] = ft_strdup(current_env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

static void	delete_value(t_minishell *minishell, char *var, int var_line)
{
	(void)var;
	if (var_line == -1)
	{
		perror("Error\nThe var doesn't exist\n");
		return ;
	}
	if (!&new_env)
	{
		perror("Error\nCouldn't create the new env");
		return ;
	}
	free_env(minishell->env);
	minishell->env = new_env(minishell->env, var_line);
}

int	ft_unset(t_command *command, t_minishell *minishell)
{
	int	i;

	i = 1;
	if (nbr_of_line(command->arg) >= 2)
	{
		while (command->arg[i])
		{
			delete_value(minishell, command->arg[i], get_env_var(minishell,
					command->arg[i], ft_strlen(command->arg[i])));
			i++;
		}
	}
	if (!minishell->env)
	{
		perror("Error\nThe new env is messed up!\n");
		return (1);
	}
	return (0);
}

// add check for the value that has been unset
// on line 71 add if 
