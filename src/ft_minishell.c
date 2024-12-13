/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 03:21:06 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 08:53:13 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_line(char **line, char *prompt, t_minishell *m)
{
	free(*line);
	*line = NULL;
	if (set_signals_to_minishell() == -1)
		return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	*line = readline(prompt);
	if (set_signals_to_ignore() == -1)
		return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	if (g_sig == SIGINT)
	{
		g_sig = 0;
		m->exit_status[0] = 130;
	}
	if (*line == NULL)
		return (free(prompt), EXIT_EOF);
	else if ((*line)[0] == '\0')
	{
		m->exit_status[0] = 0;
	}
	else
		add_history(*line);
	return (free(prompt), EXIT_SUCCESS);
}

/**
 * brief : adds the line to history, parses it,
	executes it then returns exit status
 *
 *  */
static void	process_input_line(char **line, t_minishell *m)
{
	t_command	*c;

	c = parsing(*line, m);
	*line = NULL;
	if (PARSING_LEAK_TRACKING)
	{
		free_command(c);
		printerr("%s\n\tPARSING_LEAK_TRACKING: ON !%s\n\n", \
										AINSI_BLUE, AINSI_RESET, c);
	}
	else
		m->exit_status[0] = ft_exec(&c, m);
}

int	ft_minishell(t_minishell *m)
{
	char	*line;
	char	*prompt;

	line = NULL;
	prompt = NULL;
	using_history();
	while (1)
	{
		prompt = display_prompt(m);
		get_line(&line, prompt, m);
		if (!line)
			return (EXIT_EOF);
		else if (*line)
			process_input_line(&line, m);
		if (restore_std_fds(m->std_fds) == -1)
			return (m->exit_status[0] = ERR);
	}
}
