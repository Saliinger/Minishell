/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:30:29 by m0rgenstern       #+#    #+#             */
/*   Updated: 2024/08/03 16:31:43 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# ifndef VERBOSE
#  define VERBOSE 0
# endif

enum e_errors
{
	ERR_MALLOC = 42,
	ERR_ARGS,
	ERR_OUT,
	ERR_CMD,
	ERR_PARSE,
};

enum e_primitive_errors
{
	ERR_OUTFILE = 2,
	ERR_OPEN,
	ERR_CLOSE,
	ERR_FORK,
	ERR_CHILD,
	ERR_LAST_CHILD = 127,
	ERR_PARENT,
	ERR_ACCESS
};

int	ft_error(char *error_msg, int errnum);

#endif