/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:23:53 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/09 18:34:51 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	checker_command(char *in, char *command)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (in[i])
	{
		if (in[i] != command[j])
			break ;
		i++;
		j++;
	}
	if (i == ft_strlen(command))
		return (true);
	else
		return (false);
}

int	nbr_of_line(char **env)
{
	int	i;

	if (!env)
		return (0);
	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**get_env(char **env)
{
	int		i;
	char	**res;
	int		nbr_lines;

	i = 0;
	nbr_lines = nbr_of_line(env);
	if (!env)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (nbr_lines + 1));
	if (!res)
		return (NULL);
	while (i < nbr_lines)
	{
		res[i] = ft_strdup(env[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_print(char **s, int i)
{
	if (!s)
	{
		fprintf(stderr, "Error: NULL pointer passed to ft_print.\n");
		return ;
	}
	printf("this is the args \n");
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}

void	ft_print_redir(t_redir *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("node %d: %s\n", i, list->redir);
		i++;
		list = list->next;
	}
}

int	in_quote(int status, char type)
{
	if (type == '\"' && status == 0)
		return (1);
	else if (type == '\'' && status == 0)
		return (-1);
	else if ((type == '\"' && status == 1) || (type == '\'' && status == -1))
		return (0);
	return (status);
}

char	**add_line(char **tab, char *to_add)
{
	char	**res;
	int		i;
	int		tab_size;

	if (!tab || !to_add)
		return (NULL);
	tab_size = nbr_of_line(tab);
	res = (char **)malloc(sizeof(char *) * (tab_size + 2));
	if (!res)
		return (ft_free_tab(tab), NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
		{
			ft_free_tab(res);
			return (NULL);
		}
		i++;
	}
	res[i] = ft_strdup(to_add);
	if (!res[i])
	{
		ft_free_tab(res);
		return (NULL);
	}
	res[i + 1] = NULL;
	ft_free_tab(tab);
	return (res);
}
