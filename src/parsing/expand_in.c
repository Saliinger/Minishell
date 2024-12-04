///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   expand_in.c                                        :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2024/11/29 21:47:15 by anoukan           #+#    #+#             */
///*   Updated: 2024/11/30 16:13:55 by anoukan          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../../include/minishell.h"
//
//static char	*expanded(t_minishell *minishell, char *var, int type)
//{
//	char	*res;
//	int		len;
//	int		line;
//
//	len = ft_strlen(var);
//    if (var[0] == '?' && len == 1 + type)
//        res = ft_itoa(minishell->res_last_command);
//    else
//    {
//        line = get_env_var(minishell, var, len - type);
//        if (line == -1)
//            return (NULL);
//        res = ft_strdup(minishell->env[line] + len + 1 - type);
//    }
//	return (res);
//}
//
//int in_quote(int status, char type)
//{
//    if (type == '\"' && status == 0)
//        return (1);
//    else if (type == '\'' && status == 0)
//        return (-1);
//    else
//        return (0);
//}
//
//int get_var_name(char *arg)
//{
//    int len;
//
//    len = 0;
//    while(arg[len] && arg[len] != ' ' && arg[len] != '\t')
//        len++;
//    return (len);
//}
//
//char	**expand_in(char **arg, t_minishell *minishell)
//{
//	int		i;
//    int     j;
//    int     k;
//    int    status;
//	char	**new_arg;
//
//    (void)minishell;
//
//	new_arg = (char **)malloc(sizeof(char *) * (nbr_of_line(arg) + 1));
//	if (!new_arg)
//		return (NULL);
//	i = 0;
//	while (arg[i])
//	{
//        j = 0;
//        k = 0;
//        status = 0;
//        while (arg[i][j])
//        {
//            if (arg[i][j] == '\"' || arg[i][j] == '\'')
//                status = in_quote(status, arg[i][j]);
//            if (arg[i][j] == '$' && status >= 0)
//                // add expand part + check if the var exist if it doesn't let blank
//                ;
//            else
//                new_arg[i][k] = arg[i][j];
//        }
//		i++;
//	}
//	new_arg[i] = NULL;
//	free_env(arg);
//	return (new_arg);
//}
