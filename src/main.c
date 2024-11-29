/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:10 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/29 04:42:49 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

static t_minishell	*init(char **env, char *pwd, int* adr_int)
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
	minishell->std_fds[0] = -1;
	minishell->std_fds[1] = -1;
	minishell->exit_status = adr_int;
	minishell->hidden_env = NULL;
	return (minishell);
}

volatile sig_atomic_t g_sig = NO_SIG;

int	main(int ac, char **av, char **env)
{
	int			exit_status;
	t_minishell	*minishell;
	char		buffer[4096 + 1];

	(void)av;
	if (ac > 1)
		return (printerr("err: case not asked by subject\n."), 1);
	set_signals_to_minishell();
	minishell = init(env, getcwd(buffer, 4096), &exit_status);
    if (!minishell)
		return (1);
	if (save_std_fds(minishell->std_fds) == -1)
		return (ERR_PRIM);
	ft_minishell(minishell);
	clear_history();
	free_t_minishell(&minishell);
	return (exit_status);
}
