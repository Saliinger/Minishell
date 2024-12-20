/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:10 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/13 20:02:11 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	minishell->std_fds[0] = -1;
	minishell->std_fds[1] = -1;
	minishell->paths = NULL;
	minishell->exit_status = 0;
	minishell->hidden_env = NULL;
	minishell->exportList = init_export_list(minishell->env);
	merge_sort(minishell->exportList);
	return (minishell);
}

volatile sig_atomic_t	g_sig = NO_SIG;

int	main(int ac, char **av, char **env)
{
	int			exit_status;
	t_minishell	*minishell;
	char		buffer[4096 + 1];

	if (set_signals_to_ignore() == -1)
		return (printerr("%s: %d: err", __FILE__, __LINE__), ERR_PRIM);
	(void)av;
	if (ac > 1 || (isatty(STDIN_FILENO) == false) \
										|| (isatty(STDOUT_FILENO) == false))
		return (write(STDERR_FILENO, \
								"err: case not asked by subject.\n", 32), 1);
	exit_status = 0;
	minishell = init(env, getcwd(buffer, 4096));
	if (!minishell)
		return (1);
	if (save_std_fds(minishell->std_fds) == -1)
		return (ERR_PRIM);
	ft_minishell(minishell);
	if (ft_close_saved_std_fds(minishell->std_fds) == -1)
		return (ERR_PRIM);
	rl_clear_history();
	exit_status = minishell->exit_status;
	free_t_minishell(&minishell);
	return (exit_status);
}
