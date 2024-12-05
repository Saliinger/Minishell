/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:47:15 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/30 16:13:55 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*expanded(t_minishell *minishell, char *var, int start)
{
	char	*res;
	int		len;
	int		line;
    char *extend;
    char *to_extend;

    while (var[start + len] && var[start + len] != '$' && var[start + len] != '<' &&
        var[start + len] != '>' && var[start + len] != '\'' && var[start + len] != '\"')
        len++;
    to_extend = (char *) malloc(sizeof(char) * len + 1);
    if (!to_extend)
        return (NULL);
    ft_strlcpy(to_extend, var + start, len);
    line = get_env_var(minishell, to_extend, len);
    if (line == -1)
        return (free(to_extend),ft_strdup(""));
    res = (char *) malloc(sizeof(char) * (ft_strlen(var) + ft_strlen(extend)) + 1);
	return (res);
}

int in_quote(int status, char type)
{
    if (type == '\"' && status == 0)
        return (1);
    else if (type == '\'' && status == 0)
        return (-1);
    else
        return (0);
}

int get_var_name(char *arg)
{
    int len;

    len = 0;
    while(arg[len] && arg[len] != ' ' && arg[len] != '\t')
        len++;
    return (len);
}

char	**expand_in(char **arg, t_minishell *minishell)
{
	int		i;
    int     j;
    int     k;
    int    status;
	char	**new_arg;

	new_arg = (char **)malloc(sizeof(char *) * (nbr_of_line(arg) + 1));
	if (!new_arg)
		return (NULL);
	i = 0;
	while (arg[i])
	{
        j = 0;
        k = 0;
        status = 0;
        while (arg[i][j])
        {
            if (arg[i][j] == '\"' || arg[i][j] == '\'')
                status = in_quote(status, arg[i][j]);
            if (arg[i][j] == '$' && status >= 0)
                // add expand part + check if the var exist if it doesn't let blank
                new_arg[i] = expanded(minishell, arg[i], j);
            else
                new_arg[i][k] = arg[i][j];
        }
		i++;
	}
	new_arg[i] = NULL;
	free_env(arg);
	return (new_arg);
}
