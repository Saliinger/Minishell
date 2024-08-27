/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:10 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 12:32:11 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	get_line(char **line, char *prompt)
{
	*line = readline(prompt);
}

int	main(int ac, char **av, char **env)
{
	char		*line;
	char		*prompt;
	t_minishell	*minishell;
	char		buffer[4096 + 1];

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (!minishell)
		return (1);
	minishell->env = env;
	minishell->pwd = getcwd(buffer, 4096);
	while (1)
	{
		display_prompt(&prompt, minishell);
		signal(SIGINT, sighandler);
		get_line(&line, prompt);
		free(prompt);
		using_history();
		if (!line)
		{
			free(line);
			continue ;
		}
		if (*line)
		{
			add_history(line);
			parsing(line, minishell);
		}
	}
	exit_shell(false);
	return (0);
}
