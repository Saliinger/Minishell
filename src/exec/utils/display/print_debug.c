/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:25:40 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 17:14:03 by ekrebs           ###   ########.fr       */
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
			printerr("\t\t[%d]: %s\n", i, tab[i]);
			i++;
		}
		printerr("\t\t[%d]: %p\n",  i, NULL);
	}
	else
		printerr("\t%p\n", NULL);
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
				if (file->type == 0)
					printerr("\t%d: %s: %s\n", i, "R_IN_F  ", file->path[i]);
				if (file->type[i] == 1)
					printerr("\t%d: %s: %s\n", i, "R_OUT_AP", file->path[i]);
				if (file->type[i] == 2)
					printerr("\t%d: %s: %s\n", i, "R_OUT_F ", file->path[i]);
				if (file->type[i] == 3)
					printerr("\t%d: %s: %s\n", i, "REDIR_HEREDOC ", file->path[i]);
				i++;
			}
            if(file->type[i] == 0)
			    printerr("\t%d: %p: %p\n",  i, NULL, file->path[i]);
            else
                printerr("\t%d: ERR - %d: %p\n",  i, file->type[i], file->path[i]);
		}
		else
			printerr("\t%p\n", NULL);
	}
	else
		printerr("file: %p\n", NULL);
}

void	printparse(t_parse *parse)
{
	printerr("\n\n\n");
	while (parse)
	{
		printerr("\n\n\n_______________cmd_______________\n\n\n");
		//printerr("cmd:\t%s\n", parse->redir[0]);
		printerr("REDIRS (int *tokens & char **args):\n");
		printredir(parse->redir);
		printerr("ARGS (execve tab):\n");
		printtabs(parse->redir);
		parse = parse->next;
	}
}*/
