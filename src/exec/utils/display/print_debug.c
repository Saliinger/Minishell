/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:25:40 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 04:41:17 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"

void	printtabs(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_print_err("\t\t[%d]: %s\n", i, tab[i]);
			i++;
		}
		ft_print_err("\t\t[%d]: %p\n",  i, NULL);
	}
	else
		ft_print_err("\t%p\n", NULL);
}
/*
void	printredir(t_redir *file)
{
	int	i;
	
	i = 0;
	if (file)
	{
		if(file->path)
		{
			while (file->path && file->path[i])
			{
				if (file->token == 0)
					ft_print_err("\t%d: %s: %s\n", i, "R_IN_F  ", file->path[i]);
				if (file->token[i] == 1)
					ft_print_err("\t%d: %s: %s\n", i, "R_OUT_AP", file->path[i]);
				if (file->token[i] == 2)
					ft_print_err("\t%d: %s: %s\n", i, "R_OUT_F ", file->path[i]);
				if (file->token[i] == 3)
					ft_print_err("\t%d: %s: %s\n", i, "REDIR_HEREDOC ", file->path[i]);
				i++;
			}
            if(file->token[i] == 0)
			    ft_print_err("\t%d: %p: %p\n",  i, NULL, file->path[i]);
            else
                ft_print_err("\t%d: ERR - %d: %p\n",  i, file->token[i], file->path[i]);
		}
		else
			ft_print_err("\t%p\n", NULL);
	}
	else
		ft_print_err("file: %p\n", NULL);
}

void	printparse(t_parse *parse)
{
	ft_print_err("\n\n\n");
	while (parse)
	{
		ft_print_err("\n\n\n_______________cmd_______________\n\n\n");
		//ft_print_err("cmd:\t%s\n", parse->args[0]);
		ft_print_err("REDIRS (int *tokens & char **args):\n");
		printredir(parse->redir);
		ft_print_err("ARGS (execve tab):\n");
		printtabs(parse->args);
		parse = parse->next;
	}
}*/
