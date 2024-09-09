/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:15 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/14 17:34:52 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h> 

# ifndef STDOUT
#  define STDOUT 1
# endif

# ifdef __linux__
#  define STR_NULL_PTR "(nil)"
# else 
#  define NULL_PTR "0x0"
# endif

typedef enum e_printf_errors
{
	ERROR_FTPRINTF = -1,
	CRASH_WRITE = -2,
	CRASH_NULL = -3,
	CRASH_MALLOC = -4,
	ERROR = -666
}	t_errors;

//#----------[   .   ]----------#//

/*
 * @return number of char written, -1 if failed
 */
int		ft_printf(char *str, ...);

//#----------[./flags]----------#//
int		ft_flag_c(unsigned char c, int *error);
int		ft_flag_s(const char *s, int *error);
int		ft_flag_p(const void *p, int *error);
int		ft_flag_d(int d, int *error);
int		ft_flag_i(int i, int *error);
int		ft_flag_u(unsigned int u, int *error);
int		ft_flag_x(unsigned long long x, int *error);
int		ft_flag_upper_x(unsigned int X, int *error);
int		ft_flag_unknown(char c, int *error);

//#----------[./utils]----------#//
int		ft_printf_putchar(const unsigned char c, int *error);
int		ft_printf_putstr(const char *str, int *error);
int		ft_printf_strlen(const char *str, int *error);
char	*ft_printf_itoa(long int n, int *error);
char	*ft_itox(unsigned long long x, int *error);
#endif