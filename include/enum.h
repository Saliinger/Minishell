/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:07:08 by anoukan           #+#    #+#             */
/*   Updated: 2024/11/28 04:45:07 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_redir
{
    REDIR_IN = 1,
    REDIR_OUT,
    REDIR_APPENDS_TO_FILE,
    REDIR_HEREDOC,
    REDIR_HEREDOC_MODE_IN_QUOTES,
	R_INVALID
}	t_enum_redir;

typedef enum e_cmd_type
{
	CMD_BUILTIN = 1,
	CMD_EXTERN,
} t_cmd_type;

#endif
