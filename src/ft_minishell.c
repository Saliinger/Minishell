/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 03:21:06 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/29 03:47:10 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_line(char **line, char *prompt, t_minishell *m)
{
	line[0] = readline(prompt);
	if (g_sig == SIGINT)
	{
		g_sig = 0;
		m->exit_status[0] = 130;
	}
	if (line[0] == NULL)
		return (EXIT_EOF);
	else if (line[0][0] == '\0')
		m->exit_status[0] = 0;
	else
		add_history(line[0]);
	return (EXIT_SUCCESS);
}

/**
 * brief : adds the line to history, parses it, executes it then returns exit status
 * 
 *  */
static void process_input_line(char *line, t_minishell *m)
{
	t_command	*c;

	c = parsing(line, m);
	m->exit_status[0] = ft_exec(&c, m); 
}
int	ft_minishell(t_minishell *m)
{
	char		*line;
	char		*prompt;

	line = NULL;
	prompt = NULL;
	using_history();
	while (1)
	{
		prompt = display_prompt(prompt, m);
		get_line(&line, prompt, m);
		if (!line)
			return (EXIT_EOF);
		else if (*line)
			process_input_line(line, m);
		//break; //temporaire si tu veux tester un seul input
	}
	return (EXIT_SUCCESS);
}
