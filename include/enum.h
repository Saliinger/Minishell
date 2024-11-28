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
	R_IN_FILE = 1,
	R_IN_HD,
	R_OUT_FILE,
	R_OUT_APPEND,
	R_INVALID
}	t_enum_redir;

typedef enum e_cmd_type
{
	CMD_BUILTIN = 1,
	CMD_EXTERN,
} t_cmd_type;

#endif
