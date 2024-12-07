/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:02:11 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/07 10:41:54 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	get_var_name(char *arg)
{
	int	len;

	len = 0;
	if (arg[len] == '$')
		len++;
    if (arg[len] == '?')
        return (2);
    while (arg[len] && (ft_isalpha(arg[len]) || ft_isdigit(arg[len])
			|| arg[len] == '_'))
		len++;
	return (len);
}

char *clean_name(char *var)
{
    int len = 0;
    char *res;

    len = get_var_name(var);
    res = (char *) malloc(sizeof(char) * len + 1);
    ft_strlcpy(res, var, len + 1);
    return (res);
}

static char	*expanded(t_minishell *minishell, char *var, int *start,
		char *new_arg)
{
	char	*res;
	char	*var_name;
	char	*extend;
	int		line;
	int		k;

	k = 0;
	var_name = clean_name(var + *start);
    if (!var_name)
		return (ft_strdup(""), NULL);
	line = get_env_var(minishell, var_name + 1, ft_strlen(var_name) - 1);
	if (line == -1)
	{
        res = ft_strdup("");
        while (*start > k)
        {
            res = add_char(res, var[k]);
            k++;
        }
        *start += ft_strlen(var_name);
        if (var_name[1] == '?' && ft_strlen(var_name) == 2)
        {
            k = 0;
            int *code = minishell->exit_status;
            char *exit_code = ft_itoa(*code);

            while (exit_code[k])
            {
                res = add_char(res, exit_code[k]);
                k++;
            }
        }
		return (free(var_name), res);
	}
    free(var_name);
	extend = minishell->env[line] + ft_strlen(var_name) + 2;
	res = ft_strdup("");
	if (!new_arg)
	{
		while (*start > k)
		{
			res = add_char(res, var[k]);
			k++;
		}
	}
	else
	{
		while (new_arg[k])
		{
			res = add_char(res, new_arg[k]);
			k++;
		}
		free(new_arg);
	}
	k = 0;
	while (extend[k])
	{
		res = add_char(res, extend[k]);
		k++;
	}
	*start += ft_strlen(var_name) + 2;
	return (res);
}

char	**expand_in(char **arg, t_minishell *minishell)
{
	int		i;
	int		j;
	int		status;
	char	**new_arg;

	new_arg = (char **)malloc(sizeof(char *) * (nbr_of_line(arg) + 1));
	if (!new_arg)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		j = 0;
		status = 0;
		new_arg[i] = NULL;
		while (arg[i][j])
		{
			if (arg[i][j] == '\"' || arg[i][j] == '\'')
			{
				if (!new_arg[i])
					new_arg[i] = ft_strdup("");
				if (!new_arg[i])
					return (ft_free_tab(new_arg), NULL);
				status = in_quote(status, arg[i][j]);
				new_arg[i] = add_char(new_arg[i], arg[i][j]);
				if (!new_arg[i])
					return (ft_free_tab(new_arg), NULL);
				j++;
			}
			else if (arg[i][j] == '$' && arg[i][j + 1] && status >= 0)
			{
				new_arg[i] = expanded(minishell, arg[i], &j, new_arg[i]);
				if (!new_arg[i])
					return (ft_free_tab(new_arg), NULL);
			}
			else
			{
				if (!new_arg[i])
					new_arg[i] = ft_strdup("");
				if (!new_arg[i])
					return (ft_free_tab(new_arg), NULL);
				new_arg[i] = add_char(new_arg[i], arg[i][j]);
				if (!new_arg[i])
					return (ft_free_tab(new_arg), NULL);
				j++;
			}
		}
		i++;
	}
	new_arg[i] = NULL;
	ft_free_tab(arg);
	return (new_arg);
}
