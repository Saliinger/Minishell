/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:13:49 by anoukan           #+#    #+#             */
/*   Updated: 2024/10/09 15:47:18 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	add_expand(char **clean_arg, t_minishell *minishell)
{
	int	i;
	int	var;
	int	var_len;

	i = 0;
	while (clean_arg[i])
	{
		var = 0;
		var_len = 0;
		if (clean_arg[i][0] == '$')
		{
			var_len = ft_strlen(clean_arg[i]);
			var = get_env_var(minishell, clean_arg[i], var_len);
			free(clean_arg[i]);
			printf("ENV TO DUP: %s\n", minishell->env[1]);
			clean_arg[i] = ft_strdup("test");
		}
		i++;
	}
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
	while (arg[i])
	{
		if (!is_redirection(arg[i]) && (i == 0 || !is_redirection(arg[i - 1])))
		{
			res[j] = ft_strdup(arg[i]);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	add_expand(res, minishell);
	return (res);
}

// todo:
// - add expand to replace some arg in the res
