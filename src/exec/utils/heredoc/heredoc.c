/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:31:51 by ekrebs            #+#    #+#             */
/*   Updated: 2024/12/13 07:54:01 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

char	*process_variable(t_minishell *m, char *result, \
													const char *line, size_t *i)
{
	size_t	start;
	size_t	end;
	char	*var_name;
	char	*var_value;

	start = *i + 1;
	end = start;
	while (line[end] && (ft_isalnum(line[end]) || line[end] == '_'))
		end++;
	var_name = ft_substr(line, start, end - start);
	var_value = get_env_value(m->env, var_name);
	free(var_name);
	*i = end - 1;
	return (ft_strjoin_frees1(result, var_value));
}

char	*expand_variables(t_minishell *m, char *line)
{
	char	*result;
	size_t	i;
	size_t	len;

	result = strdup("");
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1])
			result = process_variable(m, result, line, &i);
		else
		{
			len = find_next_dollar(line, i);
			result = append_to_result(result, &line[i], len);
			i += len - 1;
		}
		i++;
	}
	return (free(line), result);
}

bool	should_i_expand(char *key)
{
	int	len;

	len = ft_strlen(key);
	if (key[0] == '\'' && key[len] == '\'')
		return (false);
	return (true);
}

char	*get_the_line(char *key, int *exit_case, t_minishell *m)
{
	char	*line;

	*exit_case = EXIT_SUCCESS;
	if (set_signals_to_heredoc() == -1)
		return (printerr("%s: %d: err\n", __FILE__, __LINE__), \
													*exit_case = SIGINT, NULL);
	line = readline(">");
	if (set_signals_to_ignore() == -1)
		return (free(line), printerr("%s: %d: err\n", __FILE__, __LINE__), \
													*exit_case = SIGINT, NULL);
	if (g_sig == SIGINT)
	{
		g_sig = NO_SIG;
		if (restore_std_fds(m->std_fds) == -1)
			printerr("%s:%d: error restoration std fds\n", __FILE__, __LINE__);
		return (free(line), *exit_case = SIGINT, NULL);
	}
	if (!line)
		return (printerr("minishell: warning: %s (wanted `%s')\n", \
			"here-document delimited by end-of-file", key), \
													*exit_case = EOF, NULL);
	return (line);
}

char	*heredoc(char *key, t_minishell *m)
{
	int		exit_case;
	char	*line;
	char	*heredoc_buffer;
	bool	should_expand;

	line = NULL;
	heredoc_buffer = strdup("");
	should_expand = should_i_expand(key);
	while (1)
	{
		line = get_the_line(key, &exit_case, m);
		if (exit_case == SIGINT)
			return (free(line), free(heredoc_buffer), NULL);
		else if (exit_case == EOF)
			return (free(line), heredoc_buffer);
		else if (strcmp(line, key) == EXIT_SUCCESS)
			return (free(line), heredoc_buffer);
		if (should_expand)
			line = expand_variables(m, line);
		heredoc_buffer = ft_strjoin_frees1(heredoc_buffer, line);
		heredoc_buffer = ft_strjoin_frees1(heredoc_buffer, "\n");
		free(line);
		line = NULL;
	}
}
