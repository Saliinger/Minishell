/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reparse_redir_files_llist.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:08:59 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/12 17:18:26 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/exec.h"


/**
 * brief :  removes nodes with rd->redir that are only '>', '>>', '<', '<<', as those aren't paths to open later.
 * 
 */
int	kill_stray_node(t_redir *rd, t_redir *prev)
{
	ft_free((void **) rd->redir);
	prev->next = rd->next;
	free(rd);
	return (EXIT_SUCCESS);
}

/**
 * brief : removes '>', '>>', '<', '<<', if those apper at the start of a rd->redir. as to only let the paths to open later.
 * 
 */
int	trim_malformed_str(t_redir *rd)
{
	char	*tmp;

	tmp = rd->redir;
	rd->redir = ft_strtrim(rd->redir, "<>");
	free(tmp);
	if (!rd->redir)
		return (printf("%s, in %s at %d : error.", __FILE__, __FUNCTION__, __LINE__ ), ERR);
	return (EXIT_SUCCESS);
}


/**
 * brief : parcours all redirs starting from rd, and trim them
 * 
 */
int trim_redirs(t_redir *rd)
{
	char	*str;
	int		err;
	t_redir	*tmp;

	if (!rd)
		return (EXIT_SUCCESS);
	str = rd->redir;
	while(rd)
	{
		tmp = rd->next;
		if (str[0] == '>' || str[0] == '<')
		{
			err = trim_malformed_str(rd);
			if (err)
				return (ERR);
		}
		rd = tmp;
	}
	return (EXIT_SUCCESS);
}

/**
 * brief : removes nodes with rd->redir that are only '>', '>>', '<', '<<', as those aren't paths to open later.
 * also removes '>', '>>', '<', '<<', if those apper at the start of a rd->redir. as to only let the paths to open later.
 * DOES NOT HANDLE CASE OF FIRST NODE TO BE REMOVED;
 * 
 * ex1 : 
 * 	 	">file1"	-   R_IN_FILE
 * =>	"file1"		-	R_IN_FILE
 * 
 * 
 * ex2 :
 * 	 	">"	-   R_IN_FILE
 * =>	(node deleted)
 * 
 */
int	reparse_redir_files_llist(t_command_exec *c)
{
	int		err;

	err = 0;
	while (c)
	{
		err = trim_redirs(c->redir_files_llist);
		if (err)
			return (printf("%s, in %s at %d : error.", __FILE__, __FUNCTION__, __LINE__ ), ERR);
		c = c->next;
	}
	return (EXIT_SUCCESS);
}
