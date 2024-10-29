/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:35 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/27 13:23:12 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// echo command + option -n
//
// need to add the print of env and hidden env

#include "../../include/minishell.h"

// add of env
// special case with simple and double quote
// ❯ echo '$PWD'
// $PWD display as a word
// ❯ echo "$PWD"
// /Users/anoukan/Developer/Minishell display the env var
//
static char	*dup_env(char *env)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i] != '=')
		i++;
	if (env[i] == '=')
		i++;
	trimmed = (char *)malloc(sizeof(char *) * ft_strlen(env) - i + 1);
	if (!trimmed)
		return (NULL); // need to add an error message
	while (env[i])
	{
		trimmed[j] = env[i];
		j++;
		i++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

static char	*env_var(char *current_line, t_minishell *minishell)
{
	char	*res_env;
	size_t	i;
	int		flag;
	size_t	j;
	int		env_line;
	int		k;

	i = 0;
	flag = 0;
	j = 0;
	printf("current line: %s\n", current_line);
	while (current_line[i])
	{
		printf("current line [i]: %c\n", current_line[i]);
		if (current_line[0] == '$')
			break ;
		if (flag == 1 && current_line[i] == '$')
			break ;
		if (current_line[i] == '\"')
			flag = 1;
		if (current_line[0] == '\'')
			return (current_line);
		i++;
	}
	if (i == ft_strlen(current_line))
		return (NULL);
	if (current_line[i] == '$')
		i++;
	j = i;
	if (flag == 1)
	{
		while (current_line[i] && current_line[i] != '\"')
		{
			i++;
			if (current_line[i] == '\"')
				flag = 0;
		}
		if (flag == 1 && i == ft_strlen(current_line))
			return ("Error syntax: Fuck Off!!\n");
	}
	else if (flag == 0)
		i = ft_strlen(current_line);
	res_env = (char *)malloc(sizeof(char) * (i - j));
	if (!res_env)
		return ("Error: error malloc while getting the env var");
	k = 0;
	while (current_line[j] && j < i)
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
	res_env = dup_env(minishell->env[env_line]);
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

	is_env = NULL;
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
	int	flag;

	flag = 0;
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
