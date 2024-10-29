/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:13:49 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/29 09:41:42 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <time.h>

static bool	is_redirection(char *arg)
{
	return (!ft_strncmp(arg, "<", 1) || !ft_strncmp(arg, ">", 1)
		|| !ft_strncmp(arg, "<<", 2) || !ft_strncmp(arg, ">>", 2));
}

static int	count_line(char **arg)
{
	int	i;
	int	nbr_line;

	nbr_line = 0;
	i = 0;
	while (arg[i])
	{
		if (!is_redirection(arg[i]) && (i == 0 || !is_redirection(arg[i - 1])))
			nbr_line++;
		i++;
	}
	return (nbr_line);
}

static char	*extract_env(int var_line, char **env)
{
	char	*res;
	int		len;
	int		start;

	start = 0;
	while (env[var_line] && env[var_line][start] != '=')
		start++;
	if(env[var_line][start] == '=')
		start++;
	len = ft_strlen(env[var_line]) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strdup(env[var_line] + start);
	return (res);
}

static char *add_line(char *in, t_minishell *minishell)
{
	int		var_line;
	char	*line;

	if (in[0] == '$')
	{
		var_line = get_env_var(minishell, in, ft_strlen(in));
		if (var_line >= 0)
			line = extract_env(var_line, minishell->env);
		else
			line = ft_strdup(in);
	}
	else
		line = ft_strdup(in);
	return (line);
}

char	**clean_arg(char **arg, t_minishell *minishell)
{
	char	**res;
	int		i;
	int		j;
	int		nbr_line;

	i = 0;
	j = 0;
	nbr_line = count_line(arg);
	res = (char **)malloc(sizeof(char *) * (nbr_line + 1));
	if (!res)
		return (NULL);
	while (j < nbr_line)
	{
		while (is_redirection(arg[i]))
			i++;
		while (i > 0 && is_redirection(arg[i - 1]))
			i++;
		res[j] = add_line(arg[i], minishell);
		j++;
		i++;
	}
	res[j] = NULL;
	return (res);
}
