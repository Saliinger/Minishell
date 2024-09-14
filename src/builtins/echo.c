/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/07 16:15:06 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// echo command + option -n
//
// need to add the print of env and hidden env

#include "../../include/minishell.h"
#include <time.h>

// add of env
// special case with simple and double quote
// ❯ echo '$PWD'
// $PWD display as a word
// ❯ echo "$PWD"
// /Users/anoukan/Developer/Minishell display the env var

static char	*env_var(char *current_line, t_minishell *minishell)
{
	char	*res_env;
	int		i;
	int		flag;
	char	*var;
	int		j;
	int		env_line;
	int		k;

	i = 0;
	flag = 0;
	j = 0;
	while(current_line[i])
	{
		if (flag == 1 && current_line[i] == '$')
			break ;
		if (current_line[i] == '\"')
			flag = 1;
		i++;
	}
	if (i == ft_strlen(current_line))
		return (NULL);
	if (current_line[i] == '$')
		i++;
	j = i;
	while (current_line[i] != '\"')
		i++;
	res_env = (char *)malloc(sizeof(char) * (i - j));
	if (!res_env)
		return ("Error: error malloc while getting the env var");
	k = 0;
	while(current_line[j] && j < i)
	{
		res_env[k] = current_line[j];
		j++;
		k++;
	}
	res_env[k] = '\0';
	ft_printf("res_env: %s\n", res_env);
	env_line = get_env_var(minishell, res_env, k - 1);
	if (env_line == -1)
		return ("Error: no var");
	free(res_env);
	res_env = ft_strdup(minishell->env[env_line]);
	return (res_env);
}

static bool	flag_endl(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-' && arg[i][1] == 'n')
			return (true);
		if (arg[i][0] != '-')
			return (false);
		i++;
	}
	return (false);
}

static void	ft_print_echo(t_minishell *minishell, char **arg, int i)
{
	char	*is_env;

	while (arg[i])
	{
		if (is_env)
			free(is_env);
		is_env = env_var(arg[i], minishell);
		if (is_env)
			printf("%s", is_env);
		else
			printf("%s", arg[i]);
		if (arg[i + 1])
			printf(" ");
		i++;
	}
	if (flag_endl(arg) != true)
		printf("\n");
	if (is_env)
		free(is_env);
}

static int	flag_num(char **arg)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-')
			flag++;
		if (arg[i][0] != '-')
			return (flag);
		i++;
	}
	return (flag);
}

void	ft_echo(t_minishell *minishell, t_command *command)
{
	int	flag;

	flag = flag_num(command->arg);
	ft_print_echo(minishell, command->arg, flag);
}
