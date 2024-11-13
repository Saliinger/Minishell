/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:10 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/12 23:36:08 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	get_line(char **line, char *prompt)
{
	*line = readline(prompt);
}

static char	*init_path(t_minishell *minishell)
{
	char	*path_env;
	int		line_path;
	char	*prep;
	int		i;
	int		j;

	line_path = get_env_var(minishell, "PATH", 4);
	if (line_path == -1)
		return (NULL);
	prep = ft_strdup(minishell->env[line_path]);
	if (!prep)
		return (NULL);
	i = 0;
	while (prep[i] && prep[i] != '=')
		i++;
	if (prep[i] == '=')
		i++;
	path_env = (char *)malloc(sizeof(char) * ft_strlen(prep) - i + 1);
	if (!path_env)
		return (NULL);
	j = 0;
	while (prep[i])
	{
		path_env[j] = prep[i];
		j++;
		i++;
	}
	path_env[j] = '\0';
	return (path_env);
}

static t_minishell	*init(char **env, char *pwd)
{
	t_minishell	*minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	minishell->env = get_env(env);
	minishell->pwd = ft_strdup(pwd);
	minishell->old_pwd = ft_strdup(pwd);
	minishell->res_last_command = 0;
	minishell->paths = ft_split(init_path(minishell), ':');
	minishell->hd = (char **)malloc(sizeof(char *));
	minishell->hd[0] = NULL;
	minishell->hidden_path = NULL;
	minishell->hidden_env = NULL;
	return (minishell);
}

static void process_input_line(char *line, t_minishell *m)
{
	int			exit_status;
	t_command	*c;

	add_history(line);
	c = parsing(line, m);
	exit_status = ft_exec(&c, m); 
	free_t_command(&c);
	(void)	exit_status;
}

// need to init the path for the builtins and extern function

static void	main_extend(char *prompt, t_minishell *minishell, char *line)
{
	while (1)
	{
		prompt = display_prompt(prompt, minishell);
		//signal(SIGINT, sighandler);
		get_line(&line, prompt);
		using_history();
		if (!line)
		{
			free(line);
			continue ;
		}
		if (*line)
		{
			process_input_line(line, minishell);
		}
		break ; //KILLME
	}
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	char		*line;
	char		*prompt;
	t_minishell	*minishell;
	char		buffer[4096 + 1];

	line = NULL;
	prompt = NULL;
	minishell = init(env, getcwd(buffer, 4096));
	if (!minishell)
		return (1);
	main_extend(prompt, minishell, line);
	free_t_minishell(&minishell);
	return (EXIT_SUCCESS);
}
