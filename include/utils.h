/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 04:48:42 by ekrebs            #+#    #+#             */
/*   Updated: 2024/11/28 05:08:27 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

typedef struct s_minishell t_minishell;
typedef	struct s_command_exec t_command_exec;
typedef struct s_infos t_infos;

void	ft_free(void **add);
void	ft_free_nullterm_tab(char ***ptab);
void	free_t_command_exec(t_command_exec **head_adr);
void	free_t_command_exec_node(t_command_exec **node_adr);
void	free_t_minishell(t_minishell **ms);
void	ft_free_t_redir(t_redir **r);
void	free_t_infos(t_infos *i);
